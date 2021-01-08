import pygame
import numpy as np
from queue import PriorityQueue
class Algorithms:
    def __init__(self,height=500,width=500,n_row=20):
        self.height=height
        self.width=width
        self.n_row=n_row
        self.display=pygame.display.set_mode((height,width))

    def drawRec(self):
        sizeBlock=self.height//self.n_row
        x,y=0,0
        for i in range(self.n_row):
            x+=sizeBlock
            y+=sizeBlock
            pygame.draw.line(self.display,(255,255,255),(x,0),(x,self.height))
            pygame.draw.line(self.display,(255,255,255),(0,y),(self.height,y))

    def drawDrid(self):
        self.display.fill((0,0,0))
        self.drawRec()
        pygame.display.update()

visualization=Algorithms()

visualization.drawDrid()

