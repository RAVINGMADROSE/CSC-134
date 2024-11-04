// CSC 134
// M2LAB2 - Turtle Drawing
// Madison Moon
// 9/8/24

import turtle
t=turtle.Turtle()
t.pensize(2)
t.pencolor("purple")
t.shape("turtle")
t.speed(10)

for i in range(6):
    t.forward(300)
    t.backward(300)
    t.right(60)

side=100
t.fillcolor('orange')

t.begin_fill()

for i in range(15):
    t.penup()
    t.goto(0,0)
    t.pendown()
    t.setheading(0)
    t.forward(side)
    t.right(120)
    for j in range(6):
        t.forward(side-2)
        t.right(60)
    side=side-25

t.end_fill()
turtle.done()
