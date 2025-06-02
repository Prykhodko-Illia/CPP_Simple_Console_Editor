# 📝 Simple Text Editor

## 🚀 Project Overview
This project was aimed to create a **simple text editor**. It is written in **C++** including usage of a **structural** and **procedural** paradigm, and demonstrating usage of **classes**.

## 🗂️ Code Structure

### 📂 Files
- The main functionality is encapsulated in a header file (`.h`) with references to method implementations in different files (`.cpp`). These are used to create the text editor instance having its **private fields** and **public methods**. See more details in the [class.md](explanations/class.md) file.

- Additionally, there are sub-functions referenced in a header file made to reduce repeated parts of code.

### 🏗️ Structures
- The project defines **three main structures**:
  1. Two structures implement **linked lists** to manage strings and lines, enabling efficient text manipulation.
  2. One structure supports **undo** and **redo** operations, allowing users to revert or reapply changes easily. Learn more in the [structures.md](explanations/structures.md) file.


### ✨ Features
- Supports **15 different commands** to recreate work with the text editor.
- Two versions of the code:
  1. Based on **cursor**.
  2. Based on **user input**.

## 🧪 Usage & Testing
- This text editor has **15 useful commands** to help you work with text.
- For a full list of all commands and how to use them, please see the [commands file](explanations/commands.md).
