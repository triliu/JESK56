#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "atomic_util.h"


/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS]; // raw values
extern matrix_row_t matrix[MATRIX_ROWS];     // debounced values
//static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

static matrix_row_t read_cols(uint8_t row);
static void         init_cols(void);
static void         unselect_rows(void);
static bool         select_row(uint8_t row);     // static void         select_row(uint8_t row);
static void         unselect_row(uint8_t row);
void                matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
// static inline uint8_t readMatrixPin(pin_t pin);

static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;   //MATRIX_ROWS_PER_SIDE //#define ROWS_PER_HAND (MATRIX_ROWS / 2)
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;



static inline void setPinOutput_writeLow(pin_t pin);
static inline void setPinOutput_writeHigh(pin_t pin);
static inline void setPinInputHigh_atomic(pin_t pin);

void matrix_init_pins(void) {
    unselect_rows();
    init_cols();
}


void matrix_init_custom(void) {
    // initialize key pins
    matrix_init_pins();


    // initialize matrix state: all keys off
    memset(matrix, 0, sizeof(matrix));
    memset(raw_matrix, 0, sizeof(raw_matrix));

    debounce_init(MATRIX_ROWS);

    matrix_init_kb();
}


// Reads and stores a row, returning
// whether a change occurred.
static inline bool store_matrix_row(matrix_row_t current_matrix[], uint8_t index) {
    matrix_row_t temp = read_cols(index);
    if (current_matrix[index] != temp) {
        current_matrix[index] = temp;
        return true;
    }
    return false;
}


bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        // select rows from left and right hands
        uint8_t row_index  = i;
        if(!select_row(row_index)){
            continue;
        }

        matrix_output_select_delay();

        changed |= store_matrix_row(current_matrix, row_index);

        unselect_row(row_index);
        //matrix_output_unselect_delay(row_index, current_row_value != 0); // wait for all Col signals to go HIGH
    }
    return changed;
}






static void init_cols(void){
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (col_pins[x] != NO_PIN) {
            //setPinInputHigh(col_pins[x]);
            setPinInputHigh_atomic(col_pins[x]);
        }
    }
}

static matrix_row_t read_cols(uint8_t row) {
    if (row < MATRIX_ROWS) {
        pin_t        matrix_col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
        matrix_row_t current_row_value            = 0;
        // For each col...
        for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
            int current_diff = (col_index-row+14)%14;
            if( 
                current_diff==0 || current_diff==1 || current_diff==4 || current_diff==6 

                // (row==0 && (col_index==0 || col_index==1 ||col_index==4 || col_index==6 )) ||
                // (row==1 && (col_index==1 || col_index==2 ||col_index==5 || col_index==7 )) ||
                // (row==2 && (col_index==2 || col_index==3 ||col_index==6 || col_index==8 )) ||
                // (row==3 && (col_index==3 || col_index==4 ||col_index==7 || col_index==9 )) ||
                // (row==4 && (col_index==4 || col_index==5 ||col_index==8 || col_index==10 )) ||
                // (row==5 && (col_index==5 || col_index==6 ||col_index==9 || col_index==11 )) ||
                // (row==6 && (col_index==6 || col_index==7 ||col_index==10 || col_index==12 )) ||
                // (row==7 && (col_index==7 || col_index==8 ||col_index==11 || col_index==13 )) ||
                // (row==8 && (col_index==8 || col_index==9 ||col_index==12 || col_index==0 )) ||
                // (row==9 && (col_index==9 || col_index==10 ||col_index==13 || col_index==1 )) ||
                // (row==10 && (col_index==10 || col_index==11 ||col_index==0 || col_index==2 )) ||
                // (row==11 && (col_index==11 || col_index==12 ||col_index==1 || col_index==3 )) ||
                // (row==12 && (col_index==12 || col_index==13 ||col_index==2 || col_index==4 )) ||
                // (row==13 && (col_index==13 || col_index==0 ||col_index==3 || col_index==5 ))
            ){
                // Select the col pin to read (active low)
                uint8_t pin_state = readPin(matrix_col_pins[col_index]);

                // Populate the matrix row with the state of the col pin
                current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
            }
        }
        return current_row_value;
    }
    return -1;
}




static bool select_row(uint8_t row){
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
        setPinOutput_writeLow(pin);
        return true;
    }
    return false;
}

static void unselect_row(uint8_t row){
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
        // setPinInputHigh(pin);
        setPinInputHigh_atomic(pin);
    }
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        unselect_row(x);
    }
}







void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    if (!select_row(current_row)) { // Select row
        return;                     // skip NO_PIN row
    }
    matrix_output_select_delay();

    // For each col...
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++, row_shifter <<= 1) {

        uint8_t pin_state = readPin(col_pins[col_index]);
        // uint8_t pin_state = readMatrixPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : row_shifter;
    }

    // Unselect row
    unselect_row(current_row);
    matrix_output_unselect_delay(current_row, current_row_value != 0); // wait for all Col signals to go HIGH

    // Update the matrix
    current_matrix[current_row] = current_row_value;
}







static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinInputHigh(pin);
    }
}





// static inline uint8_t readMatrixPin(pin_t pin) {
//     if (pin != NO_PIN) {
//         return (readPin(pin) == MATRIX_INPUT_PRESSED_STATE) ? 0 : 1;
//     } else {
//         return 1;
//     }
// }





                // (row==0 && (col_index==0 || col_index==1 ||col_index==2 || col_index==3 )) ||
                // (row==1 && (col_index==10 || col_index==11 ||col_index==12 || col_index==13 )) ||
                // (row==2 && (col_index==0 || col_index==4 ||col_index==5 || col_index==10 )) ||
                // (row==3 && (col_index==3 || col_index==6 ||col_index==8 || col_index==10 )) ||
                // (row==4 && (col_index==2 || col_index==7 ||col_index==9 || col_index==10 )) ||
                // (row==5 && (col_index==0 || col_index==7 ||col_index==8 || col_index==12 )) ||
                // (row==6 && (col_index==0 || col_index==6 ||col_index==9 || col_index==13 )) ||
                // (row==7 && (col_index==1 || col_index==6 ||col_index==7 || col_index==11 )) ||
                // (row==8 && (col_index==2 || col_index==4 ||col_index==8 || col_index==11 )) ||
                // (row==9 && (col_index==3 || col_index==5 ||col_index==9 || col_index==11 )) ||
                // (row==10 && (col_index==1 || col_index==5 ||col_index==8 || col_index==13 )) ||
                // (row==11 && (col_index==1 || col_index==4 ||col_index==9 || col_index==12 )) ||
                // (row==12 && (col_index==3 || col_index==4 ||col_index==7 || col_index==13 )) ||
                // (row==13 && (col_index==2 || col_index==5 ||col_index==6 || col_index==12 ))