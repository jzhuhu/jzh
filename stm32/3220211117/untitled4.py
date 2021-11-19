# -*- coding: utf-8 -*-
"""
Created on Fri Nov 19 22:11:50 2021

@author: lenovo
"""
import cv2
import matplotlib.pyplot as plt
import numpy as np
img=cv2.imread("C:\Users\lenovo\Desktop\test.jpg")

rows,cols,channels = img.shape
a=0.18
N=7
imgxx=np.zeros((rows,cols,channels))
imgyy=np.zeros((rows,cols,channels))
img_new=np.zeros((rows,cols,channels))
for k in range(N):
    for d in range(channels):
        for i in range(1,rows-1):
            for j in range(1,cols-1):
                    imgxx[i,j,d]=int(img[i+1,j,d])+int(img[i-1,j,d])-2*int(img[i,j,d])
                    imgyy[i,j,d]=int(img[i,j+1,d])+int(img[i,j-1,d])-2*int(img[i,j,d])
                    img[i,j,d]=int(img[i,j,d])+a*(int(imgxx[i,j,d])+int(imgyy[i,j,d]))

cv2.imshow('image.jpg',img)
cv2.imwrite('image.jpg',img)

cv2.waitKey(0)
