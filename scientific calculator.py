import tkinter as tk
from tkinter import *
import time
import math
import parser
 
 
win=tk.Tk()
win.configure(bg="#000000")
win.title('JOSSY SCI CALC')
win.geometry("290x560")
win.resizable(0,0)
win.iconbitmap(r"Graphicloads-100-Flat-2-Calculator.ico")
 
def clock():
    a=time.strftime("%H:%M:%S")
    zero.config(text=a)
    zero.after(200,clock)
#functions for the calculator
 
def btnClick(numbers):
    global operator
    operator=operator+str(numbers)
    var.set(operator)
 
 
def btnclearinput():
    global operator
    operator=""
    var.set("0")
 
def btnequals():
    global operator
    sumup=str(eval(operator))
    var.set(sumup)
    operator=""
operator=""
frame1=Frame(win, height=150, width=287,bd=4,relief=SUNKEN,bg='#212121').place(x=3, y=2)
var=StringVar()
label=Label(frame1,text="CASIO\n fx-991ES PLUS", font=('showcard gothic',8,'bold'),bg="#212121",fg='grey').place(x=10, y=13)
 
#zero1=LabelFrame(frame1,width=150, height=25,bd=6,relief=SUNKEN,bg="#666633").place(x=138, y=15)
zero=Label(frame1,font=('lcd',13,'bold'),width=15,bg="#666633",relief=SUNKEN,bd=4)
zero.place(x=139, y=12)
clock()
entry=Entry(frame1,width=44, justify='right',bd=8,bg="#666633",font=('lcd',13),textvariable=var).pack(pady=45,ipady=40)
 
 
frame2=Frame(win,height=400, width=287, relief=RAISED, bd=4,bg='#212121').place(x=2, y=160)
btn1=Button(frame2,text="Shift",bd=3, width=7,bg='#ff5722',fg='black').place(x=5, y=177)
sec=Label(frame2,text="2nd", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=19, y=162)
btn2=Button(frame2,text="Alpha",bd=3, width=7,bg='#424242',fg='white').place(x=65, y=177)
btn3=Button(frame2,text="Mode",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=177)
mode=Label(frame2,text="setup", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=162)
btn4=Button(frame2,text="Calc",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=177)
calc=Label(frame2,text="solve =", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=162)
btn5=Button(frame2,text="on",bd=3, width=4,bg='#424242',fg='white').place(x=245, y=177)
btn6=Button(frame2,text="Math",bd=3, width=7,bg='#424242',fg='white').place(x=5, y=220)
btn7=Button(frame2,text="Mtrx",bd=3, width=7,bg='#424242',fg='white').place(x=65, y=220)
calc=Label(frame2,text="[matrix]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=205)
btn8=Button(frame2,text="Prgm",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=220)
btn9=Button(frame2,text="Log",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=220)
btn10=Button(frame2,text="In",bd=3, width=4,bg='#424242',fg='white').place(x=245, y=220)
btn11=Button(frame2,text="x-1",bd=3, width=7,bg='#424242',fg='white').place(x=5, y=263)
btn12=Button(frame2,text="Sin",bd=3, width=7,bg='#424242',fg='white').place(x=65, y=263)
sin=Label(frame2,text="sin^-1", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=248)
btn13=Button(frame2,text="Cos",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=263)
calc=Label(frame2,text="cos^-1", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=248)
btn14=Button(frame2,text="Tan",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=263)
calc=Label(frame2,text="tan^-1", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=248)
btn15=Button(frame2,text="nPr",bd=3, width=4,bg='#424242',fg='white').place(x=245, y=263)
btn16=Button(frame2,text="nCr",bd=3, width=7,bg='#424242',fg='white').place(x=5, y=306)
btn17=Button(frame2,text="n!",bd=3, width=7,bg='#424242',fg='white').place(x=65, y=306)
btn18=Button(frame2,text="hyp",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=306)
calc=Label(frame2,text="Abs[ C ]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=291)
btn19=Button(frame2,text="(",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=306)
btn20=Button(frame2,text=")",bd=3, width=4,bg='#424242',fg='white').place(x=245, y=306)
btn21=Button(frame2,text="x^2",bd=3, width=7,bg='#424242',fg='white').place(x=5, y=349)
calc=Label(frame2,text="x^3   DEC", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=19, y=334)
btn22=Button(frame2,text="M+",bd=3, width=7,bg='#424242',fg='white').place(x=65, y=349)
calc=Label(frame2,text="M-         M", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=334)
btn23=Button(frame2,text="(-)",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=349)
calc=Label(frame2,text="[ > ]    [ A ]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=334)
btn24=Button(frame2,text="pi",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=349)
calc=Label(frame2,text="STO", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=334)
btn25=Button(frame2,text="x10^x",bd=3, width=4,bg='#424242',fg='white').place(x=245, y=349)
calc=Label(frame2,text="e", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=259, y=334)
btn26=Button(frame2,text="7",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(7)).place(x=5, y=392)
calc=Label(frame2,text="CONST", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=19, y=378)
btn27=Button(frame2,text="8",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(8)).place(x=65, y=392)
calc=Label(frame2,text="CONV", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=378)
btn28=Button(frame2,text="9",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(9)).place(x=125, y=392)
calc=Label(frame2,text="CLR", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=378)
btn29=Button(frame2,text="DEL",bd=3, width=7,bg='#ff5722',fg='black').place(x=185, y=392)
calc=Label(frame2,text="INS", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=378)
btn30=Button(frame2,text="AC",bd=3, width=4,bg='#ff5722',fg='black').place(x=245, y=392)
calc=Label(frame2,text="OFF", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=259, y=378)
btn4=Button(frame2,text="4",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(4)).place(x=5, y=435)
btn4=Button(frame2,text="5",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(5)).place(x=65, y=435)
calc=Label(frame2,text="[ VECTOR ]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=420)
btn4=Button(frame2,text="6",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(6)).place(x=125, y=435)
btn4=Button(frame2,text="X",bd=3, width=7,bg='#424242',fg='white',command=lambda :btnClick('*')).place(x=185, y=435)
btn4=Button(frame2,text=chr(247),bd=3, width=4,bg='#424242',fg='white',command=lambda :btnClick('/')).place(x=245, y=435)
btn4=Button(frame2,text="1",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(1)).place(x=5, y=478)
calc=Label(frame2,text="[ STAT ]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=19, y=463)
btn4=Button(frame2,text="2",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(2)).place(x=65, y=478)
calc=Label(frame2,text="[ CMPLX", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=463)
btn4=Button(frame2,text="3",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(3)).place(x=125, y=478)
calc=Label(frame2,text="[ BASE ]", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=139, y=463)
btn4=Button(frame2,text="+",bd=3, width=7,bg='#424242',fg='white',command=lambda :btnClick('+')).place(x=185, y=478)
calc=Label(frame2,text="Pol", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=463)
btn4=Button(frame2,text="-",bd=3, width=4,bg='#424242',fg='white',command=lambda :btnClick('-')).place(x=245, y=478)
calc=Label(frame2,text="Rec", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=259, y=463)
btn4=Button(frame2,text="0",bd=3, width=7,bg='#90a4ae',fg='white',command=lambda :btnClick(0)).place(x=5, y=521)
calc=Label(frame2,text="Rnd", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=19, y=506)
btn4=Button(frame2,text=".",bd=3, width=7,bg='#424242',fg='white',command=lambda :btnClick('.')).place(x=65, y=521)
calc=Label(frame2,text="Ran# Ranint", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=79, y=506)
btn4=Button(frame2,text="%",bd=3, width=7,bg='#424242',fg='white').place(x=125, y=521)
btn4=Button(frame2,text="Ans",bd=3, width=7,bg='#424242',fg='white').place(x=185, y=521)
calc=Label(frame2,text="DRG >", font=('new time roman',5),bg='#212121',fg="#ff5722").place(x=199, y=506)
btn4=Button(frame2,text="=",bd=3, width=4,bg='#ff5722',fg='black',command=btnequals).place(x=245, y=521)
 
 
 
 
win.mainloop()
