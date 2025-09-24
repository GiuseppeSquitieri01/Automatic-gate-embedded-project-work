# Automatic Gate Embedded System 

**University of Salerno – Embedded Systems**  
Author: Giuseppe Squitieri – A.Y. 2023/2024  

## Project Description
This project implements an **embedded control system for an automatic gate**, developed using a **model-based design** approach with **Matlab/Simulink + Stateflow** and subsequent automatic C code generation for embedded deployment.  

The goal is to design a system capable of:  
- Managing **automatic opening and closing** of the gate.  
- Handling **external events** (button presses, open/close commands).  
- Activating **emergency mode** under critical conditions.  
- Ensuring safety, fault tolerance, and compliance with timing specifications.  

---

## Main Components
- **Stateflow model**: finite state machine of the gate (open, closed, opening, closing, emergency).  
- **Embedded C code** automatically generated using **Embedded Coder (ERT)**.  
- **Technical reports** (`.pdf`) including:
  - project requirements,  
  - state diagrams,  
  - test results (with images of transitions and scenarios).  

---

## Repository Structure
├── STATE_PROJECT.slx # Simulink/Stateflow model
├── AutomaticGate_ert_rtw/ # Auto-generated Embedded C code
├── Sistemi-embedded_consegna_due/ # Technical report + test images
├── Sistemi-embedded_consegana_tre/ # Second delivery with updates
├── Traccia Progetto-2.pdf # Official project specification
└── Automatic_Gate_Group_08.zip # Shared group project archive


---

## ⚙️ Software Architecture
The system logic is implemented with **Stateflow**:  

- **Main states**:
  - `Closed` → gate closed.  
  - `Opening` → transition from closed to open.  
  - `Open` → gate fully open.  
  - `Closing` → transition from open to closed.  
  - `Emergency` → safety state, triggered in case of error or critical event.  

- **Input events**:
  - Button presses (`B1`, `B2`, `B3`).  
  - Safety sensor signals.  
  - Timeout or environmental conditions.  

- **Output actions**:
  - Motor commands for opening/closing.  
  - Immediate stop in case of emergency.  
  - Visual/state indication.  

---

## How to Run
1. Open `STATE_PROJECT.slx` in **Matlab/Simulink**.  
2. Simulate the model to verify state transitions.  
3. Generate C code using **Embedded Coder** (ERT target).  
4. Compile and deploy the code on the embedded platform (e.g., STM32).  
5. Validate the implementation using the test scenarios in the documentation (`Sistemi-embedded_consegna_due/Immagini_Test/`).  

---

## 👨‍💻 Author
- Giuseppe Squitieri
- Gaetano Rea  
- Giuseppe Marotta  
- Davide Tramice
