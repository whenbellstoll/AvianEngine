# ViewPort
The ViewPort acts as the camera of a particular GameNode. It is defined by a rectangle and cannot be placed out of bounds. By default there is only one ViewPort per GameNode. ViewPorts can also be used as render targets for mind boggling effects, but this is not an intended use case.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| float | worldWidth | The width of the GameNode viewport is a member of, note this needs to be as wide as or wider than the viewport itself |
| float | worldHeight | The height of the GameNode viewport is a member of, note this needs to be as tall as or taller than the viewport itself |
| float | maxViewPortWorldXPos | The right bounds of the viewport X position, calculated from worldWidth and viewPort width |
| float | maxViewPortWorldYPos | The bottom bounds of the viewport Y position, calculated from worldHeight and viewPort height |
| Rect | rect | The world Rectangle object, four floats determining xpos, ypos, width, and height. |
| Rect | viewPort | The rectangle defining the current state of the viewport, xpos ypos, width, and height |
| Rect | viewPortClone | The inital state of the viewport |
| Rect | viewPortScrollingBB | The bounding box within the viewport that determines the bounds of when the viewport will be scrolled |
| Rect | initialBBClone | The rectangle with the initail state of the Bounding Box |
| float | maxInflateBBRight | The amount the scrolling bounding box is allowed to move from its defined width when the viewport is at its max X position. |
|	float | maxInflateBBLeft | The amount the scrolling bounding box is allowed to move from its defined width when the viewport is at x=0. |
|	float | maxInflateBBTop | The amount the scrolling bounding box is allowed to move from its defined height when the viewport is at y=0. |
|	float | maxInflateBBBottom | The amount the scrolling bounding box is allowed to move from its defined height when the viewport is at its max Y position. |
|	float	| dSBBR | Delta of the right side of the Bounding Box |
|	float | dSBBL | Delta of the left side of the Bounding Box |
|	float | dSBBT | Delta of the top of the Bounding Box |
|	float | dSBBB | Delta of the bottom of the Bounding Box |
| DeltaScroll | deltaScroll | The Delta of the current update, the vector the viewport is expected to move on this update |
| DeltaScroll | deltaScrollClone | The Delta of the previous update, the vector the viewport may have moved last update |

## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | All Optional Parameters: wW is the WorldWidth, wH is the WorldHeight, worldX is the ViewPort x position, worldY is the ViewPort y position, width is how many pixels wide the viewport is, height is how many pixels tall the viewport is | ViewPort(float wW = 1280,float wH = 720,float worldX = 0,float worldY = 0,float width = 1280,float heigth = 720) |


## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| WorldWidth() | Returns the worldWidth variable | float | The world width a.k.a. the left boundary the viewport cannot go beyond | void |
| WorldHeight() | Returns the worldHeight variable | float | The world height a.k.a the lower boundary the viewport cannot go beyond | void |
| WorldWidth(float) | Sets the worldWidth variable  | void | void | float value of the new world width or the left boundary the viewport cannot go beyond |
|	WorldHeight(float) | Sets the worldHeight variable | void | void | float value of the new world height |
|	ViewPortWidth(float) | Sets the width of the viewport | void | void | float value of the new viewport width |
|	ViewPortHeight(float) | Sets the height of the viewport | void | void | float value of the new viewport height |
|	Width() | Returns the width of the viewport | float | ViewPort rect's width | void |
|	Height() | Returns the height of the viewport | float | ViewPort rect's height | void |
|	WorldXPos() | Returns the X position of the viewport | float | ViewPort rect's x | void |
|	WorldYPos() | Returns the Y position of the viewport | float | ViewPort rect's y | void |
|	MaxViewPortWorldXPos() | Returns the maximum X position of the viewport | float | The max Y position | void |
|	MaxViewPortWorldYPos() | Returns the maximum Y position of the viewport | float | The max X position | void |
|	WorldXPos(float) | Sets the viewport x position, if greater than a bounds (0 or MaxViewPortWorldXPos()) then it will be set to those bounds | void | void | The world X position |
|	WorldYPos(float) | Sets the viewport y position, same rules as WorldXPos() | void | void | The world Y position |
|	WorldRightPos() | Returns the position of the right side of the viewport in world space (x-position + viewport width) | float | WorldXPos() + Width() | void |
|	WorldBottomPos() | Returns the position of the bottom of the viewport in world space (y-position + viewport height) | float | WorldYPos() + Height() | void | 
|	WorldRect() | Returns the Rectangle defining the world space | Rect | The world rectangle | void |
|	IntWorldRect() | Returns the world rectangle as it was at initialization | Rect | The initail world rectangle | void |
| Rect() | Returns the Rectangle defining the ViewPort | Rect | The Rectangle of the ViewPort | void |
|	Scroll(float dx,float dy) | Scroll the ViewPort by a 2D vector | const DeltaScroll & | A reference to the resulting scroll from the arguments passed in | The amount we want the viewport to scroll |
|	CurrentDeltaScroll() | Return the current scroll of the ViewPort | const DeltaScroll & | A reference to the current scroll happening to the ViewPort | void |
|	ViewPortScrollingBB(float viewPortX,float viewPortY,float width,float heigth) | Sets the bounding box that determines where scrolling occurs | void | void | viewPortX: The x position of the Bounding Box relative to the ViewPort. viewPortY: The y position of the Bounding Box relative to the ViewPort. width: Width of the new Bounding Box. height: The new height of the Bounding Box |
|	BBWidth() | Returns the width of the Bounding Box | float | The width of the Bounding Box | void |
| BBHeigth() | Returns the height of the Bounding Box | float | The height of the Bounding Box | void |
| BBWorldXPos() | Returns the X position of the Bounding Box in world space | float | The X position of the Bounding Box in world space | void |
|	BBWorldYPos() | Returns the Y position of the Bounding Box in world space | float | The Y position of the Bounding Box in world space | void |
|	BBWorldRightPos() | Returns the right side of the Bounding Box in world space | float | The position of the right of the Bounding Box in world space | void |
|	BBWorldBottomPos() | Returns the bottom of the Bounding Box in world space | float | The position of the bottom of the Bounding Box in world space | void | 
|	BBWorldRect() | Returns the Rectangle defining the Bounding Box in world space | Rect | The Bounding Box rectangle in world space | void |
|	BBViewPortXPos() | Returns the X position of the Bounding Box relative to the ViewPort | float | The X position of the Bounding Box relative to the ViewPort | void |
|	BBViewPortYPos() | Returns the Y position of the Bounding Box relative to the ViewPort | float | The Y position of the Bounding Box relative to the ViewPort | void |
|	BBViewPortRightPos() | Returns the right side of the Bounding Box relative to the ViewPort | float | The position of the right of the Bounding Box relative to the ViewPort | void |
|	BBViewPortBottomPos() | Returns the bottom of the Bounding Box relative to the ViewPort | float | The position of the bottom of the Bounding Box relative to the ViewPort | void | 
|	BBViewPortRect() | Returns the Rectangle defining the Bounding Box relative to the ViewPort | Rect | Bounding Box Rectangle relative to the ViewPort | void |
| MaxInflateBBRight() | Returns the maxInflateBBRight variable | float | The value of the max right inflation value | void |
|	MaxInflateBBLeft() | Returns the maxInflateBBLeft variable | float | The value of the max left inflation value | void |
| MaxInflateBBTop() | Returns the maxInflateBBTop variable | float | The value of the max top inflation value | void |
|	MaxInflateBBBottom() | Returns the maxInflateBBBottom variable | float | The value of the max bottom inflation value | void |
|	MaxInflateBBRight(float) | Sets the maxInflateBBRight variable | void | void | Max value of the right of the Bounding Box |
|	MaxInflateBBLeft(float) | Sets the maxInflateBBLeft variable | void | void | Max value of the left of the Bounding Box |
|	MaxInflateBBTop(float) | Sets the maxInflateBBTop variable | void | void | Max value of the top of the Bounding Box |
|	MaxInflateBBBottom(float) | Sets the maxInflateBBBottom variable | void | void | Max value of the bottom of the Bounding Box |
|	InflateBBRight(float) | Inflates the bounding box to the right, barring its maximum | float | The new right value | Additional right inflation of the Bounding Box |
|	InflateBBLeft(float) | Inflates the bounding box to the left, barring its maximum | float | The new left value | Additional left inflation of the Bounding Box |
|	InflateBBTop(float) | Inflates the bounding box to the top, barring its maximum | float | The new top value | Additional top inflation of the Bounding Box |
|	InflateBBBottom(float) | Inflates the bounding box to the bottom, barring its maximum | float | The new bottom value | Additional bottom inflation of the Bounding Box |
|	InitialBBClone() | Returns the Rectangle defining the initial state of the Bounding Box | Rect | The initial state of the Bounding Box | void |
|	RestoreBB() | Return the Bounding Box to its initial state | void | void | void |
|	DisplayBB() | Toggle the viosibility ofthe Bounding Box during gameplay | void | void | void |
|	Offset(float x,float y,bool = true) | Offset the ViewPort in world space | DeltaScroll | Scroll resulting from the arguments | x: Offset x-position y: Offset y-position, bool clamp values to integers |
|	OffsetVPSBB(float x,float y) | Offset the Bounding Box from the ViewPort | void | void | x: Offset x-position y: Offset y-position |
| Save(File &) | Serialize the ViewPort object | void | void | File to write to |
|	Load(File &) | Load the ViewPort from Serialization | void | void | File to read from |


## See Also:
[Sprites](Sprite.md)

[GameLoop](Game.md#gameloop)
