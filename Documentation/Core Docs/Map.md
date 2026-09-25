# Map

Map represents a background/level texture that Sprites move around on. `GameNode` owns the list of Maps and drives their rendering and collision each frame. For MVP, only `STANDARDMAP` (non-wrapping, static background) is fully implemented; `MASTERMAP` and `WRAPPEDMAP` are placeholder variants intended for advanced features.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| unsigned int | width, height | Real pixel dimensions of the map texture, populated by `LoadMap()` |
| float | worldPositionX, worldPositionY | The map's position in the world, in pixels |
| float | scrollingRatioX, scrollingRatioY | Parallax scroll ratio, exposed via `ScrollRatioX/Y` |
| MapType | mType | MASTERMAP, STANDARDMAP, or WRAPPEDMAP; MVP focuses on STANDARDMAP |
| int | spacePartitionGridSize | Cell size (pixels) for the spatial partition grid (default: 64) |
| Array<Array<Array<node*>>> | gridLists | 2D grid of sprite lists for spatial partitioning: `gridLists[cellX][cellY]` holds sprites in that cell |
| int | gridRows, gridColumns | Computed dimensions of the partition grid based on map size and cell size |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | Map() |
| Copy | const Map & | Map(const Map &) |
| Full | name, filename, MapType, x, y, spacePartitionGridSize, isMaster | Map(const char*, const char*, MapType, int, int, int, bool) |

## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |

## Functions:
| Signature | Description | Return type | Return value | Arguments |
| :-------- | :---------: | :----------: | :-------: | ----------: |
| Height() / Width() | Real pixel size of the loaded map texture | unsigned int | height / width | None |
| WorldPositionX() / WorldPositionY() | The map's position in the world (pixels) | float | worldPositionX / worldPositionY | None |
| WorldPositionX(float) / WorldPositionY(float) | Sets the map's world position | void | None | New position |
| WorldPositionXInc/Dec, WorldPositionYInc/Dec | Moves the map's world position by an amount, clamped to a min/max | void | None | Amount, clamp bound |
| IsMasterMap() | Whether this Map was constructed as the master map | bool | isMasterMap | None |
| ScrollRatioX/Y() and setters | Parallax scroll ratio, intended for use during Map::Execute/scrolling maps | float / void | scrollingRatioX/Y | ratio |
| DisplayMap() | Renders the map's quad at its current world position | void | None | None |
| InitGrid() | Initializes the spatial partition grid with `gridRows` and `gridColumns` based on map size and `spacePartitionGridSize` | void | None | None |
| SpacePartitionGridSize(unsigned int) / SpacePartitionGridSize() | Sets/reads the cell size of the partition grid | void / int | None / cell size | Cell size (pixels) or none |
| GridCoordsFromWorld(worldX, worldY, gridX, gridY) | Converts world coordinates to grid cell indices, with clamping | void | Updated gridX/gridY | World X/Y, grid X/Y (by ref) |
| GetGridCellsForBounds(left, top, right, bottom, minX, maxX, minY, maxY) | Returns the range of grid cells occupied by a bounding box | void | Updated grid bounds | Bounds (left, top, right, bottom) and grid bounds (by ref) |

### Implementation notes
- **MVP Map Type**: Only `STANDARDMAP` is the intended focus for the MVP. `MASTERMAP` and `WRAPPEDMAP` are declared but their rendering/collision logic (`DisplayMasterMap`, `DisplayWrappedMap`, `WrappingAlgorithm`, etc.) remains unimplemented.
- **World Positioning**: `DisplayMap()` now converts `worldPositionX/Y` (pixels) into the normalized device coordinates the vertex shader (`shader.vs`) expects, using the same `2 / global.width` / `2 / global.height` conversion the sprite pipeline uses. This lets a map actually scroll instead of always being pinned to the screen origin.
- **Spatial Partition Grid**: `InitGrid()` is called automatically in the Map constructor after `LoadMap()`. The grid divides the map into cells (default 64×64 pixels) and maintains `gridLists[x][y]` as a 2D array. Currently, the grid is initialized but not actively used for collision queries; future optimization can check only sprites in overlapping cells instead of a full O(n²) comparison. Helper functions `GridCoordsFromWorld()` and `GetGridCellsForBounds()` are available for wiring this optimization.
- **GameNode Collision**: `GameNode::Execute` treats `mapList[0]` as the "world" map for sprite-vs-map boundary collision (see [GameNode.md](GameNode.md)). Per-depth-layer or multi-map collision is not yet supported.
- **Unimplemented Features**: 
  - `UseTransparency()`/`TransparencyColor()` toggling and per-tile transparency masking.
  - Segment/circle collision data wiring (`AddCollisionData`, `RemoveCollisionData`) — the infrastructure exists but not the game-loop integration.
  - Wrapped/master map specialty behaviors.

## See Also
- [GameNode](GameNode.md)
- [CollisionData](CollisionData.md)
- [Sprite](Sprite.md)

