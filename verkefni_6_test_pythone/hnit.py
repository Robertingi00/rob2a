


class get_hnit():
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.stad = self.hnit()

    def hnit(self):
        temp_hnit = [[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
        temp_hnit[self.y][self.x] = 1
        return temp_hnit

    def get_x_y(self):
        return [self.y,self.x]


def move_to_ball(ball):
    print('-----------------')
    ball = ball.get_x_y()
    if robot.x != 1:
        if robot.x == 2:
            robot.x -= 1
        else:
            robot.x += 1
    print(robot.hnit())
    while robot.y != ball[0]:
        if robot.y < ball[0]:
            robot.y += 1
        else:
            robot.y -= 1
        print(robot.hnit())
    if ball[1] == 2:
        robot.x += 1
    else:
        robot.x -= 1
    print(robot.hnit())
    print('-----------------')







bolti1 = get_hnit(2, 0)
bolti2 = get_hnit(0, 1)
bolti3 = get_hnit(2, 2)
bolti4 = get_hnit(2, 4)

robot = get_hnit(1, 0)

karfa = get_hnit(0, 3)




boltar = [bolti1, bolti2, bolti3, bolti4]

for x in range(4):
    move_to_ball(boltar[x])
    move_to_ball(karfa)











