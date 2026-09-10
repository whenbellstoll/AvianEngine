# Map

Map represents a background/level texture (master, standard, or wrapped) that Sprites move around on. `GameNode` owns the list of Maps and drives their rendering and collision each frame.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| unsigned int | width, height | Real pixel dimensions of the map texture, populated by `LoadMap()` |
| float | worldPositionX, worldPositionY | The map's position in the world, in pixels |
| float | scrollingRatioX, scrollingRatioY | Parallax scroll ratio, exposed via `ScrollRatioX/Y` |
| MapType | mType | MASTERMAP, STANDARDMAP, or WRAPPEDMAP |


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

### Implementation notes
- `DisplayMap()` now converts `worldPositionX/Y` (pixels) into the normalized device coordinates the vertex shader (`shader.vs`) expects, using the same `2 / global.width` / `2 / global.height` conversion the sprite pipeline uses. This lets a map actually scroll instead of always being pinned to the screen origin.
- `GameNode::Execute` treats `mapList[0]` as the "world" map for sprite-vs-map boundary collision (see [GameNode.md](GameNode.md) and [Sprite collision notes](CollisionData.md)).
- `UseTransparency()`/`TransparencyColor()` toggling and `WrappingAlgorithm` (used by WRAPPEDMAP) are still stubs — there isn't yet a field tracking whether transparency is enabled, and the wrapped/master map draw paths (`DisplayMasterMap`, `DisplayWrappedMap`, `InitStandardMap`, etc.) are unimplemented. Only the single-map, non-wrapping render path used by `DisplayMap()` currently works.
- Collision data storage (`AddCollisionData`, `RemoveCollisionData`, `InitGrid`/space partition grid) is not implemented; current map collision is a simple world-boundary AABB test, not per-segment collision.

## See Also
- [GameNode](GameNode.md)
- [CollisionData](CollisionData.md)

