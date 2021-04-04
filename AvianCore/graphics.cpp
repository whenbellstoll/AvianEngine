#include "globals.h"

// took this as a template, to quickly get textured geometry
// https://github.com/JoeyDeVries/LearnOpenGL/blob/master/src/1.getting_started/4.1.textures
// starter code
Keyboard* pKeyboard;
Mouse* pMouse;
Gamepad* pGamepadOne;
Gamepad* pGamepadTwo;
Gamepad* pGamepadThree;
Gamepad* pGamepadFour;

void CheckShader(GLuint shader)
{
    GLint checkStatus;

    // get the status to see if it compiles correctly
    glGetShaderiv(shader, GL_COMPILE_STATUS, &checkStatus);

    // if the status is zero, then the compile failed
    if (checkStatus == 0)
    {
        // set length to zero by default
        GLint length = 0;

        // this gives us the length of the error message(s)
        // that the compiler found when trying to compile our code
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        // create a string that is large enough to store the
        // error message(s)
        GLchar* logData = (GLchar*)MEMPACK_AllocMem(&global.ramPack, length + 1, "CheckShader error");

        // get the error message(s) and store them into our string
        glGetShaderInfoLog(shader, length, 0, logData);

        // print the data, so that we can see the error
        printf("%s\n", logData);

        // delete the program, because it failed, it is 
        // not useful to us in any way
        glDeleteShader(shader);

        // dont erase message, we'll PopState when shaders are done
    }
}

void CheckProgram(GLuint program)
{
    //Debugging Program
    GLint checkStatus = 0;

    //This line returns a parameter from a shader program object, specified by the second parameter
    glGetProgramiv(program, GL_LINK_STATUS, &checkStatus);	//Check if the shader program linked correctly, stores result in the last parameter. Second 

    //If it's false, it didn't link properly so we have to debug it
    if (checkStatus == GL_FALSE)
    {
        GLint length = 0;
        //Same line as above, except this time we want the log data length so we can output it
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        GLchar* logData = (GLchar*)MEMPACK_AllocMem(&global.ramPack, length + 1, "CheckProgram error");

        //This line stores the information log from the shader program into a specified variable.
        glGetProgramInfoLog(program, length, 0, logData);
        printf("%s\n", logData);
        //Since we failed to create the shader program, delete any created objects
        glDeleteProgram(program);

        //Print an error messavge and return
        printf("Error linking program file\n");

        // dont erase message, we'll PopState when shaders are done
    }
}

void InitOpenGL()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    global.window = glfwCreateWindow(640, 480, "Avian Engine", NULL, NULL);
    if (global.window == NULL)
    {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
    }
    // We need to create the Keyboard at this point. Start the input
    global.keyboard = Keyboard();
    pKeyboard = &global.keyboard;
	
	// We also need to create the mouse
	global.mouse = Mouse();
	pMouse = &global.mouse;
    glfwMakeContextCurrent(global.window);

	// Gamepads as well
	pGamepadOne = new Gamepad(0);//&global.joyOne;
	pGamepadTwo = new Gamepad(1);//&global.joyTwo;
	pGamepadThree = new Gamepad(2);//&global.joyThree;
	pGamepadFour = new Gamepad(3);//&global.joyFour;


	// set callback for input and resize
	glfwSetKeyCallback(global.window, Input_Update);
    glfwSetFramebufferSizeCallback(global.window, onResize);
	glfwSetCursorPosCallback(global.window, Mouse_Position_Update);
	glfwSetMouseButtonCallback(global.window, Mouse_Update);
    // Enable GLEW, setting glewExperimental to true.
    // This allows GLEW take the modern approach to retrive function pointers and extensions
    glewExperimental = GL_TRUE;

    // Initialize GLEW to setup OpenGL function pointers
    if (GLEW_OK != glewInit())
    {
        // If the initalization is not successful, print out the message and exit the program with return value EXIT_FAILURE
        printf("Failed to initialize GLEW\n");
    }

    glEnable(GL_DEPTH_TEST);

    // set a bookmark, so we can erase all the 
    // memory we allocated when we're done with
    // shaders. This includes memory for files,
    // error messages, etc
    MEMPACK_PushState(&global.ramPack);

    FILE* file_vs = fopen("Assets/shader.vs", "rb");
    if (!file_vs)
    {
        printf("\nFailed to open Assets/shader.vs\n");
        glfwTerminate();
        while (true) {}
    }

    FILE* file_fs = fopen("Assets/shader.fs", "rb");
    if (!file_fs)
    {
        printf("\nFailed to open Assets/shader.fs\n");
        glfwTerminate();
        while (true) {}
    }

    // get size of vs
    fseek(file_vs, 0L, SEEK_END);
    int size_vs = ftell(file_vs);
    fseek(file_vs, 0L, SEEK_SET);

    // get size of fs
    fseek(file_fs, 0L, SEEK_END);
    int size_fs = ftell(file_fs);
    fseek(file_fs, 0L, SEEK_SET);

    // allocate memory
    char* shader_vs = (char*)MEMPACK_AllocMem(&global.ramPack, size_vs + 1, "vertex shader file");
    char* shader_fs = (char*)MEMPACK_AllocMem(&global.ramPack, size_fs + 1, "fragment shader file");

    // read
    fread(shader_vs, 1, size_vs, file_vs);
    fread(shader_fs, 1, size_fs, file_fs);

    // close files
    fclose(file_vs);
    fclose(file_fs);

    // create shaders and set sourcse
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vs, 1, &shader_vs, &size_vs);
    glShaderSource(fs, 1, &shader_fs, &size_fs);

    // compile shaders and check for error
    glCompileShader(vs);
    glCompileShader(fs);
    CheckShader(vs);
    CheckShader(fs);

    // link and activate program,
    // we wont use any others, so leave it in use
    global.program = glCreateProgram();
    glAttachShader(global.program, vs);
    glAttachShader(global.program, fs);
    glLinkProgram(global.program);
    CheckProgram(global.program);
    glUseProgram(global.program);

    // only for testing
#if 0
    printf("%d\n", glGetUniformLocation(program, "layer"));
    printf("%d\n", glGetUniformLocation(program, "posX"));
    printf("%d\n", glGetUniformLocation(program, "posY"));
    printf("%d\n", glGetUniformLocation(program, "scaleX"));
    printf("%d\n", glGetUniformLocation(program, "scaleY"));
#endif

    // delete shaders once program is done
    glDeleteShader(vs);
    glDeleteShader(fs);

    // erase all shader data in RAM,
    // now that we dont need it anymore
    MEMPACK_PopState(&global.ramPack);

    // Create Pixel Buffer, bind, and set size,
    // we wont use any others, so leave it in use
    glGenBuffers(1, &global.PBO);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, global.PBO);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, pboSize, nullptr, GL_STATIC_DRAW);

    // we give nullptr because this allocator is relative
    // to the start of pbo memory, so it holds offsets, 
    // not raw GPU addresses
    MEMPACK_Init(&global.pboPack, 0, pboSize, (char*)"pbo");
    MEMPACK_Init(&global.mappboPack, 0, mappboSize, (char*)"mappbo");

    // Generate and bind VAO, dont unbind
    glGenVertexArrays(1, &global.VAO);
    glBindVertexArray(global.VAO);

    // Generate and bind VBO, dont unbind
    glGenBuffers(1, &global.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, global.VBO);
    glBufferData(GL_ARRAY_BUFFER, vboSize, nullptr, GL_STATIC_DRAW);

    // we give nullptr because this allocator is relative
    // to the start of pbo memory, so it holds offsets, 
    // not raw GPU addresses
    MEMPACK_Init(&global.vboPack, 0, vboSize, (char*)"vbo");
    MEMPACK_Init(&global.mapvboPack, 0, mapvboSize, (char*)"mapvbo");


    // Vertex position and tex coordinates
    // will be in our vertex structure
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
}

void onResize(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h); // reset the viewport

}


void CleanOpenGL()
{
    MEMPACK_Clean(&global.vboPack);
    MEMPACK_Clean(&global.pboPack);
    MEMPACK_Clean(&global.mapvboPack);
    MEMPACK_Clean(&global.mappboPack);

    glDeleteVertexArrays(1, &global.VAO);
    glDeleteBuffers(1, &global.VBO);
    glDeleteBuffers(1, &global.PBO);
    glDeleteProgram(global.program);

    // destroy glfw and all it's resources
    glfwTerminate();
}