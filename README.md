# 提瓦特幸存者
# TutorialZero 
  这是一个使用 C++ 和 EasyX 图形库开发的简单游戏项目。玩家可以控制角色移动并射击敌人，游戏中包含得分系统和背景音乐。
 
  This is a simple game project developed using C++ and the EasyX graphics library. Players can control the character to move and shoot enemies. The game includes a scoring system and background music.

# 项目介绍 
# Project Introduction

## 依赖项 
## Dependencies

- Visual Studio 2019 或更高版本 Visual Studio 2019 or higher
- EasyX 图形库 EasyX Graphics Library

## 安装和运行 
## Installation and Running

1. 克隆项目到本地：git clone https://github.com/tuzibuqiahuluobo/TutorialZero.git

   Clone the project to local: git clone https://github.com/tuzibuqiahuluobo/TutorialZero.git

2. 打开 Visual Studio，使用 `File -> Open -> Project/Solution` 打开 `Game.sln` 解决方案文件。
 
   Open Visual Studio and use `File -> Open -> Project/Solution` to open the `Game.sln` solution file.

3. 确保已安装 EasyX 图形库，并在项目属性中正确配置库和包含目录。

   Make sure the EasyX Graphics Library is installed and the library and include directories are correctly configured in the project properties.

4. 生成解决方案并运行项目。

   Build the solution and run the project.

## 游戏玩法 
## Gameplay

- 使用键盘方向键控制角色移动。
- 游戏开始后，敌人会不断生成，玩家需要躲避敌人并让小球在旋转的途中攻击敌人。
- 每击中一个敌人得一分，在玩家触碰到敌人时，游戏结束将会，并且显示最终得分。

- Use the keyboard arrow keys to control the character's movement.
- After the game starts, enemies will continue to spawn, and the player needs to dodge the enemy and let the ball attack the enemy while rotating.
- Each enemy hit will score one point. When the player touches the enemy, the game will end and the final score will be displayed.

## 项目结构 
## Project structure

游戏图像资源 
Game image resources

├── img/          

游戏音频资源  
Game audio resources

├── mus/   

源代码文件 
Source code files

├── src/

│  ├── main.cpp 

│  ├── Globals.cpp

│  ├── Animation.cpp

│  ├── Player.cpp

│  ├── Enemy.cpp

│  ├── Bullet.cpp

│  ├── Button.cpp 

│  ├── StartGameButton.cpp 

│  ├── QuitGameButton.cpp

│  └── Utils.cpp 

├── include/

头文件  
Header files

│  ├── Globals.h 

│  ├── Animation.h 

│  ├── Player.h 

│  ├── Enemy.h 

│  ├── Bullet.h 

│  ├── Button.h 

│  ├── StartGameButton.h 

│  ├── QuitGameButton.h 

│  └── Utils.h

├── Game.sln

Visual Studio 解决方案文件  
Visual Studio Solution File

├── Game.vcxproj       

Visual Studio 项目文件
Visual Studio Project File

└── README.md          

## 贡献 
## Contributions

欢迎提交问题和拉取请求来改进这个项目。请确保在提交前阅读并遵循项目的贡献指南。

Issues and pull requests are welcome to improve this project. Please make sure to read and follow the project's contribution guidelines before submitting.

## 许可证
## License

该项目使用 MIT 许可证。详情请参阅 [LICENSE](LICENSE) 文件。

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
