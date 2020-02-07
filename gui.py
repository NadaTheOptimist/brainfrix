from tkinter import *
from tkinter import messagebox as msg
import subprocess

root = Tk()
root.title("BrainFrixIDE - 0.0.0")
codeBox = Text(root, height = 20, width = 80)

def programCheck():
    brainFrickCode = str(codeBox.get("1.0", END))
    # establishes a new Tkinter window for the program input
    root = Tk()
    root.title("Input window")
    inputBox = Text(root, height = 40, width = 80)

    def runProgram():
        # reads the timeoutlimit in the config.txt file
        f = open("config.txt", 'r')
        TimeOutLimit = int(f.read().split("\n")[0].split("=")[1])
        f.close()

        # gets the code and input from their windows
        brainFrickCode = str(codeBox.get("1.0", END))
        brainFrickCodeInput = str(inputBox.get("1.0", END))
        
        # runs the code 
        try:
            output = subprocess.check_output("brainfrick.exe", input = (brainFrickCode + "\n" + brainFrickCodeInput).encode(), stderr = subprocess.STDOUT, timeout = TimeOutLimit)
        except subprocess.TimeoutExpired:
            msg.showerror("Error", "Your code ran for more than the timeout limit, and as such was shut down. Error x001, subprocess.TimeOutExpired")
        
        root = Tk()
        # opens the output window
        root.title("Output window")
        codeOutput = Text(root, height = 40, width = 80)
        codeOutput.insert("1.0", output)
        codeOutput.pack()
        
        root.mainloop()
    
    # packs and mainloops root
    runButton = Button(root, text = "run", command = runProgram)
    inputBox.pack()
    runButton.pack()
    root.mainloop()
    
   
interpretButton = Button(root, text = "INTERPRET", command = programCheck)

codeBox.pack()
interpretButton.pack()

root.mainloop()
