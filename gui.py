from tkinter import *
from tkinter import messagebox as msg
import subprocess

root = Tk()
root.title("BrainFrick IDE -1.0.2")
codeBox = Text(root, height = 20, width = 80)
programInput = Entry(root)
def programCheck():
    f = open("config.txt", 'r')
    TimeOutLimit = int(f.read().split("\n")[0].split("=")[1])
    f.close()
    brainFrickCode = str(codeBox.get("1.0", END)).replace("\n", '')
    brainFrickCodeInput = str(programInput.get())
    try:
        output = subprocess.check_output("brainfrick.exe", input = (brainFrickCode + "\n" + brainFrickCodeInput).encode(), stderr = subprocess.STDOUT, timeout = TimeOutLimit)
    except subprocess.TimeoutExpired:
        msg.showerror("Error", "Your code ran for more than the timeout limit, and as such was shut down. Error x001, subprocess.TimeOutExpired")
    
    msg.showinfo("RESULT", output.decode())
interpretButton = Button(root, text = "INTERPRET", command = programCheck)

codeBox.pack()
programInput.pack()
interpretButton.pack()

root.mainloop()