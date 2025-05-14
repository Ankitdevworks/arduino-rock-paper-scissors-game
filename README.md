# 🎮 Arduino Rock-Paper-Scissors Game

This is a fun Rock-Paper-Scissors game built using an **Arduino Uno** and a **16x2 LCD** display.

The user enters their move via the **Serial Monitor**, and the computer responds with a randomly selected move. Both moves and the result are displayed on the LCD screen.

---

## 🧰 Components Used

- Arduino Uno
- LCD 16x2 Display
- Breadboard & jumper wires
- USB cable (for serial input)

---

## 💻 How It Works

1. LCD shows a prompt to enter a move.
2. User types `STONE`, `PAPER`, or `SCISSOR` in the Serial Monitor.
3. The Arduino:
   - Validates the input
   - Randomly generates the computer's move
   - Displays both moves
   - Shows the result: You Win / Computer Wins / Draw

---

## 🔍 Code Highlights

- Input validation using string comparison
- Random generation using `randomSeed()`
- LCD display logic with cursor positioning
- Clear modular functions for readability

---

## 📸 Demo

*You can upload an image of your hardware or LCD output here.*

```bash
images/demo.jpg
