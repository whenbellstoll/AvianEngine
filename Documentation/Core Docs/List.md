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
| node* Clone() | 
| node* Head() |
| node* Sentinel() |
| bool EOList() |
| void add( node * ) |
| void add( node *, node * ) |
| void del() |
| void remove(node *) |
| unsigned int Count() |
| void Save(File &) |
| void Load(File &) |

## See Also
[GameNode](GameNode.md)
