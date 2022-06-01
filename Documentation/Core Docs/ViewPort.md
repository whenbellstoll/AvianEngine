# ViewPort
The ViewPort acts as the camera of a particular GameNode. It is defined by a rectangle and cannot be placed out of bounds. By default there is only one viewport per GameNode.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| float | worldWidth |  |
| float | worldHeight |  |
| float | maxViewPortWorldXPos |  |
| float | maxViewPortWorldYPos |  |
| FRECT | rect |  |
| FRECT | viewPort |  |
| FRECT | viewPortClone |  |
| FRECT | viewPortScrollingBB |  |
| FRECT | initialBBClone |  |
| float | maxInflateBBRight |  |
|	float | maxInflateBBLeft |  |
|	float | maxInflateBBTop |  |
|	float | maxInflateBBBottom |  |
|	float	| dSBBR |  |
|	float | dSBBL |  |
|	float | dSBBT |  |
|	float | dSBBB |  |
| DeltaScroll | deltaScroll |  |
| DeltaScroll | deltaScrollClone |  |

## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | All optional parameters, wW is the WorldWidth, wH is the WorldHeight, worldX is the ViewPort x position, worldY is the ViewPort y position, width is how many pixels wide the viewport is, height is how many pixels tall the viewport is | ViewPort(float wW = 640,float wH = 480,float worldX = 0,float worldY = 0,float width = 640,float heigth = 480) |


## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| WorldWidth() | Returns the world width given to the viewport | float | The world width a.k.a. the left boundary the viewport cannot go beyond | void |
| WorldHeight() | Returns the world height given to the viewport | float | The world height a.k.a the lower boundary the viewport cannot go beyond | void |
| WorldWidth(float) |  |  |  | float value of the new world width |
|	WorldHeight(float) |  |  |  | float value of the new world height |
|	ViewPortWidth(float) |  |  |  | float value of the new viewport width |
|	ViewPortHeight(float) |  |  |  | float value of the new viewport height |
|	float Width() |  |  |  | void |
|	float Height() |  |  |  | void |
|	float WorldXPos() |  |  |  | void |
|	float WorldYPos() |  |  |  | void |
|	float MaxViewPortWorldXPos() |  |  |  | void |
|	float MaxViewPortWorldYPos() |  |  |  | void |
|	void WorldXPos(float) |  |  |  |  |
|	void WorldYPos(float) |  |  |  |  |
|	float WorldRightPos() |  |  |  |  |
|	float WorldBottomPos() |  |  |  | void | 
|	FRECT WorldRect() |  |  |  | void |
|	FRECT  IntWorldRect() |  |  |  | void |
| FRECT Rect() |  |  |  | void |
|	const DeltaScroll & Scroll(float dx,float dy) |  |  |  |  |
|	const DeltaScroll & CurrentDeltaScroll() |  |  |  | void |
|	void ViewPortScrollingBB(float viewPortX,float viewPortY,float width,float heigth) |  |  |  |  |
|	float BBWidth() |  |  |  | void |
|	float BBHeigth() |  |  |  | void |
|	float BBWorldXPos() |  |  |  | void |
|	float BBWorldYPos() |  |  |  | void |
|	float BBWorldRightPos() |  |  |  | void |
|	float BBWorldBottomPos() |  |  |  | void | 
|	FRECT BBWorldRect() |  |  |  | void |
|	float BBViewPortXPos() |  |  |  | void |
|	float BBViewPortYPos() |  |  |  | void |
|	float BBViewPortRightPos() |  |  |  | void |
|	float BBViewPortBottomPos() |  |  |  | void | 
|	FRECT BBViewPortRect() |  |  |  | void |
| float MaxInflateBBRight() |  |  |  | void |
|	float MaxInflateBBLeft() |  |  |  | void |
|	float MaxInflateBBTop() |  |  |  | void |
|	float MaxInflateBBBottom() |  |  |  | void |
|	void MaxInflateBBRight(float) |  |  |  |  |
|	void MaxInflateBBLeft(float) |  |  |  |  |
|	void MaxInflateBBTop(float) |  |  |  |  |
|	void MaxInflateBBBottom(float) |  |  |  |  |
|	float InflateBBRight(float) |  |  |  |  |
|	float InflateBBLeft(float) |  |  |  |  |
|	float InflateBBTop(float) |  |  |  |  |
|	float InflateBBBottom(float) |  |  |  |  |
|	FRECT InitialBBClone() |  |  |  | void |
|	void RestoreBB() |  |  |  | void |
|	void DisplayBB() |  |  |  | void |
|	DeltaScroll Offset(float x,float y,bool = true) |  |  |  |  |
|	void OffsetVPSBB(float x,float y) |  |  |  |  |
|	void Save(File &) |  |  |  |  |
|	void Load(File &) |  |  |  |  |


## See Also:
[Sprites](Sprite.md)
[GameLoop](Game.md#gameloop)
