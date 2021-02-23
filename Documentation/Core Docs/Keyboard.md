# Key


## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| bool | PreviousState | Tracks if the key has been updated |
| bool | Press | Tracks whether a key is pressed |
| bool | Trigger | Tracks the first frame a key is pressed |
| unsigned int | TapCounter | How many times a key has been tapped within a tracking period |
| unsigned int | TapCounterP | Period in frames a tap will increment the tap counter |
| unsigned int | HoldCounter | How many frames have passed since this key was first pressed |

# Keyboard


## Fields:
| Type    | Name      | Description |
| :------------- | :----------: | -----------: |
| Window | hWnd | A reference to the game window (OS dependent) |
| Key | keys | Array of all the keys |
| Double | elements | Keeps track of the keys pressed on this frame (max of 8) |
| KImp * | pKImp | A dummy pointer for accessing the Keyboard class |
| Input | InputInstance | The Input processor that polls the Keyboard for updates |


## Constuctors
| Type | Arguments | Signature |
| :--- | :-------: | --------: |
| Default | Window and Instance (type is OS dependent) | Keyboard(Window, Instance) |
| Destructor | N/A | ~Keyboard() |

## Functions:
| Signature | Description | Return type | Return value | Arguments | 
| :-------- | :---------: | :----------: | :-------: | ----------: |
| IsPressed(unsigned char) | Detects the pressed key on the keyboard.  Returns as true when the key is pressed. | bool | If the key is pressed | The desired key |
| IsNotPressed(unsigned char) | This function detects if the key is not pressed. IsNotPressed function returns as true when the key is not pressed. | bool | If the key is not being pressed | The desired key |
| IsTriggered(unsigned char) | Detects if the key is triggered.  Returns as true when the key status changes from not pressed to pressed. | bool | If the key is triggered | The desired key |
| IsNotTriggered(unsigned char) | Detects if the key is not triggered.  Returns as false when the key status changes from not pressed to pressed. | bool | If the key is not triggered | The desired key |
| GetKey( unsigned char & ) | Fills a reference to an unsigned char and assigns whatever key is currently triggered. | bool |  true if a key is triggered else false | Address is assigned the current triggered key |
| Nothing() | Returns true if no key is pressed on the current frame | bool | True if no keys are pressed, otherwise false | None |
| Any() | Returns true if any key is pressed, otherwise false. | bool | True if any key is pressed, otherwise false | None |
| GetCharAsString() | Returns the current triggered key as string | const char * | The triggered key as a null terminated string, if no key then returns an empty string "" | None |
| GetString(char * , unsigned int) | Assign a string keys the user types, cease when either enter or the max number is reached | unsigned int | 0 if empty, 1 if enter was pressed, 2 if full | Argument 1: The string to be filled Argument 2: The maximum length of the string |
| TapCounter(unsigned char) | Returns how many frames have passed since a key was pressed to a max of 256 | unsigned int | How many frames since the key has been pressed | The desired key |
| HoldCounter(unsigned char) | Returns how many frames a key has been held | unsigned int | How many frames the key has been held | The desired key |
| StartReceivingData() | | void | | |
| StopReceivingData() | | void | | |
| Update(unsigned char * & keysPressed ) | Updates the state of the keys | unsigned int | returns success 1 or failure 0 | The keys that were pressed on the previous frame |
| Reset() | Set Keyboard to deafult state | void | None | None |



## See Also
