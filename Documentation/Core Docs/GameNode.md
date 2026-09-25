# GameNode

GameNode represents a level/scene: it owns the Sprites and Maps that belong to it and drives the per-frame update loop (`Execute`), including rendering maps/sprites and resolving collisions between them.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| Array\<node *\> | spriteList | All Sprites that belong to this GameNode |
| Array\<node *\> | mapList | All Maps that belong to this GameNode; `mapList[0]` is treated as the world/boundary map |
| ViewPort | viewPort | The camera/viewport for this GameNode |
| Behavior * | behavior | Level-wide behavior (functions run every frame, independent of any Sprite) |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | GameNode() |

## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |

## Functions:
| Signature | Description | Return type | Return value | Arguments |
| :-------- | :---------: | :----------: | :-------: | ----------: |
| Execute(float dt) | Renders all Maps and Sprites, updates Sprite translation/animation/behavior, and resolves Sprite-vs-Map and Sprite-vs-Sprite collisions | void | None | Delta time |
| Add(Sprite *) / Add(Sprite &) | Adds a Sprite to spriteList (bounded by spriteMaximum) | bool | Whether the sprite was added | Sprite pointer/reference |
| Add(Map *) / Add(Map &) / AddMap(...) | Adds a Map to mapList (bounded by mapMaximum) | bool | Whether the map was added | Map pointer/reference or construction args |

### Implementation notes: collision pass in Execute()
`Execute` now performs two collision passes after updating all Sprites:
1. **Sprite vs Map** — for any Sprite with `CheckCollisionWithMap()` enabled, its bounding box is tested against the bounds of `mapList[0]` (`WorldPositionX/Y` + `Width()/Height()`). The result is stored via `Sprite::CollisionWithMap(bool)`, queryable with `Sprite::CollisionWithMap()`. Only a single "world" map is considered; per-map or per-tile collision is not implemented (see [Map.md](Map.md)).
2. **Sprite vs Sprite** — an O(n²) pass compares every pair of Sprites that both have `CheckCollisionWithSprite()` enabled using the existing `CheckSpriteCollision`. On collision, each Sprite's name is recorded in the other's `collidedSprites` list, which `Sprite::CollisionWithSprite(name)` queries (NULL name means "did this sprite collide with anything this frame?"). The list is cleared at the start of every frame.

This is an MVP implementation: it is correct for small numbers of sprites but is not spatially partitioned. Partition grid infrastructure is available in `Map` (`InitGrid()`, `GridCoordsFromWorld()`, `GetGridCellsForBounds()`, and the `gridLists` 2D array); future optimization can check only sprites in overlapping cells instead of all pairs. The grid has a conservative default cell size (64 pixels) and is initialized when each Map is loaded.

## See Also
- [Map](Map.md)
- [CollisionData](CollisionData.md)

