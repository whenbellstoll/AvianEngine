# Bnode

Bnode is short hand for behavior node, it contains a function pointer and a few other fields that make it more convient for the Behavior class to manipulate.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| int | Index | Index of the node in the Behavior class |
| bool | Active | Will the function attached to this node run on Update |
| int | type | -1 = nothing, 0 = function, 1 = statemachine, 2 = timer |
| void * | f | Function pointer |
| StateMachineTraverser * | smt | If the Bnode reference a state machine this object navigates the states |
| Timer | tm | Acts as the timer for timer-based functions, fires after an interval |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | Bnode() |
| Copy | Bnode address | Bnode(const Bnode &) |

## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Copy assignment | const Bnode & | Bnode & operator = (const Bnode &) |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| Save(File &) | Saves the Bnode to a file | void | None | File address being written |
| Load(File &) | Loads a Bnode from a file | void | None | File address being read |

# Behavior
The behavior class is fundamental to the modularity of the engine. It provides the means of adding functions as compenents to nearly every higher level object in the engine including levels, sprite, maps, and the global game state itself.

## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| std::vector<Bnode> | Bnodes | The vector of behavior nodes attached to this behavior class |
| std::vector<int> | FunctionIndexes | |
| std::vector<int> | StateMachinesIndexes | |
| std::vector<int> | TimerIndexes | |
| bool | IsRunning | Is the behavior looping through the Bnodes this frame? |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | None | Behavior() |


## Operators
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Copy assignment | const Behavior & | Behavior & operator=(const Behavior &) |


## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| AddStateMachine(unsigned int, bool) | Add a State Machine Bnode to the Behavior | void | None | Index of the StateMachine. Is the StateMachine Active.  |
| AddFunction(unsigned int, bool) | Add a Function Bnode to the Behavior | void | None | Index of the Function. Is the Function Active.  |
| AddTimer(unsigned int, bool) | Add a Timer Bnode to the Behavior | void| None | Index of the Timer. Is the Timer Active.  |
| IsStateMachineAdded(unsigned int) | Checks if the StateMachine is currently in the Behavior | bool | True if the StateMachine is in the Behavior, false otherwise | Index of StateMachine |
| IsFunctionAdded(unsigned int) | Checks if the Function is currently in the Behavior | bool | True if the Function is in the Behavior, false otherwise | Index of Function |
| IsTimerAdded(unsigned int) | Checks if the Timer is currently in the Behavior | bool | True if the Timer is in the Behavior, false otherwise | Index of Timer |
| StateMachineActiveStatus(unsigned int, bool) | Set the active boolean true or false, "pausing" or "updating" a Bnode | void | None | Index of State Machine. Active Status.  |
| FunctionActiveStatus(unsigned int, bool) | Set the active boolean true or false, "pausing" or "updating" a Bnode | void | None | Index of Function. Active Status. |
| TimerActiveStatus(unsigned int, bool) | Set the active boolean true or false, "pausing" or "updating" a Bnode | void | None | Index of Timer. Active Status. |
| StateMachineActiveStatus(unsigned int) | Gets whether a Bnode is active | bool | Active Status | Index of StateMachine |
| FunctionActiveStatus(unsigned int) | Gets whether a Bnode is active | bool | Active Status | Index of Function |
| TimerActiveStatus(unsigned int) | Gets whether a Bnode is active | bool | Active Status | Index of Timer |
| ChangeState(unsigned int, unsigned int) | Explictly change the state of a state machine | void | None | Index of StateMachine, Index of State to change to |
| GetCurrentState(unsigned int) | Returns the current state of an added State Machine | int | Index of current State | Index of StateMachine |
| Clear() | Removes all Bnodes from Behavior | void | None | None |
| Count() | The count of the Bnodes vector | unsigned int | How many Bnode are attached to the Behavior | None |
| ResetTimer(unsigned int i, unsigned int delay, TimerMode mode = TM_Infinite ) | Explicitly reset a timer | void | None | Index of the Timer. How many Frames / GameLoops the delay should be. Mode of the Timer (Fire Once or Infinite) |
| TimeRemaining(unsigned int) | Get how many frames / gameloops remain on a timer | unsigned int | The number of frames / game loops left before the timer expires | Index of Timer |
| Update(void * ) | Update the Bnodes | void | None | Function pointer of the first active Bnode |
| Save(File &) | Saves the Behavior object to a file | void | None | File address being written |
| Load(File &) | Loads a Behavior object from a file | void | None | File address being read |

## See Also
