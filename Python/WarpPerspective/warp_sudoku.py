import matplotlib.pyplot as plt
import numpy as np
import cv2

img = cv2.imread('sudoku_result.png')
rows,cols,ch = img.shape

print rows,cols

cv2.circle(img,(100,60), 7, (255,0,0), -1)
cv2.circle(img,(260,60), 7, (255,0,0), -1)
cv2.circle(img,(100,180), 7, (255,0,0), -1)
cv2.circle(img,(260,180), 7, (255,0,0), -1)
cv2.circle(img,(100,300), 7, (255,0,0), -1)
cv2.circle(img,(260,300), 7, (255,0,0), -1)

cv2.circle(img,(20,60), 7, (0,255,0), -1)
cv2.circle(img,(340,60), 7, (0,255,0), -1)
cv2.circle(img,(60,180), 7, (0,255,0), -1)
cv2.circle(img,(300,180), 7, (0,255,0), -1)



#pts1 = np.float32([[100,60],[260,60],[100,300],[260,300]])
#pts2 = np.float32([[20,60],[340,60],[100,300],[260,300]])

pts1 = np.float32([[100,60],[260,60],[100,300],[260,300]])
pts2 = np.float32([[20,60],[340,60],[100,300],[260,300]])

M = cv2.getPerspectiveTransform(pts1,pts2)
dst = cv2.warpPerspective(img,M,(360,360),cv2.WARP_INVERSE_MAP)


plt.subplot(121),plt.imshow(img),plt.title('Input')
plt.subplot(122),plt.imshow(dst),plt.title('Output')
plt.show()
