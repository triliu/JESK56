# JESK56

The JESK56 is a diodeless 56-key ortholinear keyboard, using a single QMK-compatible RP2040-based microcontroller. The JESK56 utilises a new type of circuit design stemming from graph theory and mathematical design theory. All previous diodeless keyboards on the market have at most 21 keys per microcontroller. So all such keyboards must be split into two halves to function as a regular keyboard, and must use two microcontrollers over the two halves. This makes the JESK56 the first non-split diodeless keyboard. 

Due to its diodeless-ness, the JESK56 is ideal for the custom keyboard community, as it reduces the cost and complexity of making a custom mechanical keyboard.

<img src="https://github.com/triliu/JESK56/assets/3928134/cca97c47-b7c1-420f-9098-3839783bdc04" width="380">
<img src="https://github.com/triliu/JESK56/assets/3928134/03baaf90-4083-4bb8-b3fc-9f85ba9a2aec" width="380">

## Why 'JESK'?

Typical mechanical keyboards arrange their keys in a grid pattern. In such a grid, there are cycles of four keys. If no diodes were used and three keys of a four-key cycle were pressed, the keyboard would act like all four keys were being pressed. See https://pcbheaven.com/wikipages/How_Key_Matrices_Works/ for an explainer of this phenomenon. By adding a diode to every key, the keyboard becomes "n-key rollover", meaning that the keyboard can theoretically distinguish all combinations of keypresses. In software, however, 6-key rollover is typically used, meaning the software assumes that if more than six keys are being pressed, then keys were pressed on accident. The USB keyboard protocol is limited to a 6-key rollover. 

In graph theory, it is possible to make graphs that do not contain small cycles. Each graph can be converted into a new type of key matrix, with differing characteristics. A recent paper studied graphs of high algebraic connectivity; see [Attainable bounds for algebraic connectivity and maximally-connected regular graphs](https://arxiv.org/abs/2307.07308). They found a graph of girth 6 (no 3-, 4-, or 5-cycles) with 28 vertices and 56 edges. JESK is an acronym of the four authors' surnames: Janssen, Exoo, Salamon, and Kolokolnikov. 

<img src="https://github.com/triliu/JESK56/assets/3928134/93b0413c-0de7-4808-ae9d-428fda9361e3" width="240">


For more details on this graph, see [House of Graphs](https://houseofgraphs.org/graphs/49998). This converts to a key matrix with just a 4-key rollover. However, by designing the board specifically, all problematic 5-key and 6-key sequences may be practically eliminated, giving the JESK56. 

## What files are here
- Gerber files for production
- QMK firmware
- 3D files for the case
