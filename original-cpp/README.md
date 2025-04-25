# 🥖 Original C++ Version of Crumb Chronicles

![Crumb Chronicles Screenshot](https://i.imgur.com/N6A7zNG.png)

This folder contains the original text-based implementation of "Interview With A Sentient Toaster" that was created as a C++ console application.

## 📄 Files in this folder

- `CrumbChronicles.cpp` - The complete source code for the game
- `CrumbLeaderboard.txt` - The leaderboard file where player results were saved
- `CrumbChronicles` - The compiled executable (if included)

## ⚙️ How to Compile

If you want to run the original C++ version, you can compile it using:

```bash
clang++ -std=c++11 CrumbChronicles.cpp -o CrumbChronicles
```
## ▶️ How to Play

After compiling, run the executable:

```bash
./CrumbChronicles
```

## 🔄 Key Differences from the Web Version

- 🖋️ Simulated typing effect via slower text printing  
- 📁 Local file-based leaderboard (`CrumbLeaderboard.txt`)  
- 🎨 ASCII art displayed directly in the console  
- 🤖 Same quirky toaster personality with multiple ending paths  

---

## 🖥️ System Requirements

- C++11-compatible compiler  
- Standard C++ libraries (no external dependencies)

---

## 🛠️ Original Development

Developed as a **first-year university project**, this game demonstrates:

- Handling user input  
- Using control structures (`if`, `else`, `switch`)  
- ASCII art creation  
- File I/O for saving scores  
- Basic game state logic
