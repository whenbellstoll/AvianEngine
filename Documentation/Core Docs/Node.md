# Node

Node is the base class for a large portion of the classes in Avian, providing the most basic function of storing some given data and organizing by pointing at the next node.
It is especially integral to the List class, and is how most objects (GameNodes, Sprites, Sounds, MovementPatterns, etc.) are stored in the engine. 
It also provides the virtual functions for serialization.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
|  node * | next   | The next node in the list, null if node is last    |
|  node * | previous | The previous node in the list, null if first |
|  node * | local | A local node that can store any class that derives from the class |

## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | node() |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| node * Next() | Returns the next node in the list. | node pointer | The next node in the list | None | 
| node * Previous() | Returns the previous node in the list. | node pointer | The previous node in the list | None |
| bool EOList() | Determines if this node is the end of the list. | boolean | Returns true if the node is the end of the list, otherwise false. | None |
| virtual node * Clone() | Method to duplicate the current node into an empty one. | node pointer | Returns a true copy of the node in a new space of memory. | None |
| virtual void Load(File &){} | Virtual function for reading objects into memory from writing | void | None | File address being read |
| virtual void Save(File &){} | Virtual function for serialization of objects | void | None | File address being written to |
| virtual const char * ClassName() | Returns the name of the current class | const char pointer | The name of the class: "node" | None |
