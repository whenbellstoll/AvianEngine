# List

List is a data structure in Avian that stores a set of nodes in sequence.
There can be any number of nodes in a given list to the unsigned integer maximum.
The starting node is denoted as the head and the ending node is denoted as the sentinel.
Many objects are stored in the List data structure in the engine, it's reccomended that any custom class or type that is used often and is used in a GameNode to GameNode context, rather than global, inhert from node as to be able to interface with the List data structure. 

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| node * | head | The start of the list |
| node * | sentinel | The end of the List |
| unsigned int | count | How many nodes are contained in the list |

## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | List() |
| Copy | Constant List Address | List( const List &) |

## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Simple assignment | Constant List Address | List & operator=(const List &) |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| node* Clone() | Converts the list into a node for purposes of storage and reference | node pointer | The List casted as a node | None |
| node* Head() | Method returning node that starts the list | node pointer | The starting node | None |
| node* Sentinel() | Method returning node terminating the list | node pointer | The end node | None |
| bool EOList() | Method to check if a node in the list is the Sentinel | bool | True if the node is the  sentinel, false otherwise | None |
| void add( node * ) | Method to append a node to the end of the List | void | None | node pointer to add to the list |
| void add( node *, node * ) | Method to insert a node into the List at a given node within the list | void | None | Node pointer to current element, node pointer to new element |
| void del() | Method to delete the current data in the list | void | None | None |
| void remove(node *) | Method to remove a specific node currently in the list | void | None | Node pointer to be removed |
| unsigned int Count() | Method to get the count of the list | unsigned integer | The number of nodes in the list | None |
| void Save(File &) | Method the serialize the state of the list into a file | void | None | File address being written to |
| void Load(File &) | Method to retrieve a List object from a file | void | None | File address being read from |

## See Also
[GameNode](GameNode.md)
