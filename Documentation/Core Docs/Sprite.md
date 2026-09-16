# Sprite

Sprite represents any moving/animated actor placed on a Map (the player, enemies, projectiles, etc). It owns its own `Behavior` component, its animation/frame state (backed by the shared `SpriteList` actor definitions), and per-frame translation. `GameNode` owns the list of Sprites and drives `UpdateSprite()`/collision resolution for all of them (see [GameNode.md](GameNode.md)).

This document currently focuses on the collision- and position-related surface area, since that is what the MVP pass implemented. See `SpriteFull.h` for the full public API (movement patterns, path state machines, alarms, network fields, etc. are declared but not yet implemented).

## Fields (partial, collision/position-relevant):
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| float | mapPositionX, mapPositionY | Position in normalized device coordinates (-1..1), matching the vertex shader's `posX`/`posY` uniforms |
| bool | mapCollision | Toggle: should `GameNode::Execute` test this sprite against the map boundary each frame? Set via `CheckCollisionWithMap(bool)` |
| bool | mapCollisionFlag | Result: did this sprite collide with the map last frame? Set by `GameNode::Execute`, read via `CollisionWithMap()` |
| bool | spriteCollision | Toggle: should this sprite be tested against other sprites? Set via `CheckCollisionWithSprite(bool)` |
| Array\<String\> | collidedSprites | Names of sprites this sprite collided with last frame, populated by `GameNode::Execute` (friend), queried via `CollisionWithSprite(name)` |

## Functions (implemented in this pass):
| Signature | Description | Return type | Return value | Arguments |
| :-------- | :---------: | :----------: | :-------: | ----------: |
| CheckSpriteCollision(Sprite*) | Real AABB test between this sprite and another, using the current animation frame's bounding box | bool | Whether the boxes overlap | Other sprite |
| CheckCollisionWithMap(bool) / CheckCollisionWithMap() | Enables/disables per-frame map-boundary collision checking for this sprite | void / bool | None / current toggle | Enabled flag |
| CollisionWithMap(bool) / CollisionWithMap() | Stores/reads the result of the last map collision test | void / bool | None / last result | Result flag |
| CheckCollisionWithSprite(bool) / CheckCollisionWithSprite() | Enables/disables per-frame sprite-vs-sprite collision checking for this sprite | void / bool | None / current toggle | Enabled flag |
| CollisionWithSprite(const char* n = NULL) | Whether this sprite collided with anything (n == NULL) or a specific named sprite, last frame | bool | Result | Sprite name or NULL |
| TempCheckCollisionWithMap(left, top, right, bottom) | Real AABB test between this sprite and a rectangle (used by `GameNode` with the world map's bounds); returns true once the sprite crosses outside the rectangle | bool | Whether the sprite is outside the given bounds | Rectangle bounds (pixels) |
| Width() / Height() | Real pixel size of the current animation frame | unsigned int | Frame width/height | None |
| MapPositionXInc/Dec, MapPositionYInc/Dec | Moves the sprite's NDC position by an amount, clamped to a min/max | void | None | Amount, clamp bound, ignore-flag |

### Open items / not yet implemented
- `TempCheckCollisionWithMap(float,float,float,float,int)` (the 5-argument overload) and `TempCheckCollisionWithSprite` are still stubs; only the collision paths GameNode actually uses were implemented.
- Sprite has no `Map*` back-reference (`BelongToMapPtr` is commented out in the header), so real per-Map (rather than single "world map") collision, and any wall/slope-accurate collision via `CollisionSegment`/`CollisionCircle`, is not possible yet without restoring that reference or otherwise associating a Sprite with a specific Map.
- Movement patterns, path state machines, gravity, flipping, alarms, and the commented-out network block are declared but unimplemented (see the corresponding `.md` files, most of which are still empty templates).

## See Also
- [GameNode](GameNode.md)
- [Map](Map.md)
- [CollisionData](CollisionData.md)
- [Behavior](Behavior.md)
