import pandas as pd
import math as ma
import numpy as np
from nearest_neighbors import plot_cities

def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def sort(): # 데이터 파일을 날짜순으로 정렬
    f =open('./stock_history.csv', 'r')
    lines = f.readlines()
    f.close()
    list = lines[1:]
    del lines[1:]
    list.reverse() # 기존에 정렬돼있던 날짜를 역순으로 바꿔줘서 하루 전날 비교할 수 있도록 정렬함
    list = lines + list
    f=open('./new_test.csv', 'w')
    for line in list:
        line = line.strip()
        f.write(line)
        f.write('\n')
    f.close()

def verse(): #ud_Nd가 한줄씩 입력될 때 경우가 나뉘기 때문에 따로 함수를 작성(N = 3일경우)
    i=0
    count = 0
    while i < (len(df.index)-1): # 파일의 크기만큼 반복
        i = i + 1
        if df['close_value'][i].item() > df['close_value'].shift(1)[i].item(): #종가의 값이 어제보다 오늘 상승했을 경우
            u1 = 0
            count += 1
            if count < 0: #이전에 종가의 연속 감소로 인해 count 값이 음수일 경우에 초기화가 필요 (ex, 이틀연속 감소하다 증가했을 경우)
                count =1
            if count >= 2:#3일 연속으로 증가할 시
                u1 = 1 # 1 데이터 삽입
        elif df['close_value'][i].item() < df['close_value'].shift(1)[i].item():#종가의 값이 어제보다 하락했을 경우
            u1 = 0
            count -= 1
            if count > 0: #이전에 종가의 연속 증가로 인해 count 값이 양수일 경우에 초기화가 필요 (ex, 이틀연속 증가하다 감소했을 경우)
                count = -1
            if count <= -2:#3일 연속으로 감소할 시
                u1 = -1 # -1 데이터 삽입
        else : # 종가의 값이 어제, 오늘 같을 경우
            u1 = 0 #0 데이터 삽입 후
            count = 0 # count값 초기화
        df.set_value(i,'ud_Nd',u1) #csv 파일에 데이터 삽입

def transe():
        df['cv_diff_value'] = df['close_value'].diff() # diff()를 통해 n번째와 n-1번째의 종가의 차를 반환한다.
        df['cv_diff_rate'] = df['cv_diff_value'] / df['close_value'].shift(1) # 오늘 종가 변화량과 전날 종가 변화량에 대한 비율을 구한다
        df['cv_maN_value'] = df['close_value'].rolling(window=5).mean() #rolling을 통해 이동평균을 구한다
        df['cv_maN_rate'] = (df['cv_maN_value']-df['cv_maN_value'].shift(1))/df['cv_maN_value'].shift(1) # 이동평균에 대한 변화량을 구한다
        verse()
        df['cv3d_diff_rate'] = (df['close_value'].shift(-1) - df['close_value'].shift(2)) / df['close_value'].shift(2) #n=3일 때 당일과 전날의 종가 상승률을 비교한다

df = pd.read_csv('./new_test.csv', encoding='cp949')
sort()
transe()
df.to_csv('stock_history_added.csv', mode='w')
