# Collision Data

There are currently two collision systems in the engine at different levels of completeness:

1. **AABB rectangle collision** (implemented, used by the MVP loop): `Sprite::CheckSpriteCollision(Sprite*)` and `Sprite::TempCheckCollisionWithMap(left, top, right, bottom)` build screen-space `Rect`s from a Sprite's current animation frame and world position, then call `IntersectRectangles1` (see [Clip.h](../../AvianCore/Avian/Clip.h)). `GameNode::Execute` (see [GameNode.md](GameNode.md)) drives this every frame for both Sprite-vs-Sprite and Sprite-vs-Map (world boundary) collisions. This is the MVP collision system.

2. **Segment/Circle swept collision** (`CollisionSegment`/`CollisionCircle` below): a more advanced system with real per-shape `DetectCollision()` math (normal-based, MinT/time-of-impact). Intended for precise per-edge map collision (walls, slopes, etc). This is **not yet wired into GameNode's update loop** — `Map::AddCollisionData()`/`RemoveCollisionData()`/`InitCollision()` are stubs, so there is currently no way to attach `CollisionSegment`/`CollisionCircle` data to a Map and have it checked automatically. Each `Sprite` has `ownerCollisionData`, `mapCollisionData`, and `spriteCollisionData` arrays ready to hold these shapes, but they are only queried by the Sprite's owner (not by the game loop). This is the natural next step once precise (non-rectangular) map collision is needed.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |


## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |

# Collision Segment


## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |


## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |

# Collision Circle


## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |


## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |

## See Also
