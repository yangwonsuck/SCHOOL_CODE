import pandas as pd
import math as ma
import numpy as np


def length(index1, index2,index3 ,n): #독립변수컬럼명2개를 입력받아서 유클리디안 거리를 구해서 종속변수인 ud_Nd속성과 같이 적용시킨 함수
    i = 0
    total = 0
    while i < (len(df.index) - 1):    #index길이 값 -1 만큼 반복
        i = i + 1
        k = n+1
        j = 1
        X = df[index1][i].item()      #X값은 첫번째 독립변수의 컬럼값
        y = df[index2][i].item()      #y값은 두번째 독립변수의 컬럼값
        z = df['ud_Nd'][i].item()     #z값은 종속변수인 ud_Nd의 컬럼값
        new_value = []                #새로운 리스트 생성
        while j < (len(df.index) - 1):   #이중 루프 구조 생성
            result = ma.sqrt(( ma.pow((X-df[index1][j].item()),2) + ma.pow((y - df[index2][j].item()),2)))   #유클리디안 정의에 의한 식 result값으로 정의
            z = df['ud_Nd'][j].item()
            new_value.append([result,z])        #new_value 리스트에 result와 z값 더해서 새로 만듬
            j += 1
        new_value.sort(key=lambda x: x[0])  #new_value x[0]에따라 내림차순정렬
        a=0
        result_positive = 0 #ud_Nd의 1값 변수 초기화
        result_negative = 0 #ud_Nd의 -1값 변수 초기화
        result_zero = 0   #ud_Nd의 0값 변수 초기화
        for a in range(k-1):
            count_positive =0      #ud_Nd값이 1일때 카운트 하기 위한 변수 초기화
            count_negative = 0     #ud_Nd값이 -1일때 카운트 하기 위한 변수 초기화
            count_zero = 0         #ud_Nd값이 0일때 카운트 하기 위한 변수 초기화
            if new_value[a][1] == 1:     #a값이 증가하면서 new_value의 값이 1일때 카운트값 과 new_value의 첫번째 배열값 증가
                count_positive += 1
                result_positive += new_value[a][0]
            elif new_value[a][1] == -1:    #a값이 증가하면서 new_value의 값이 -1일때 카운트값 과 new_value의 첫번째 배열값 증가
                count_negative += 1
                result_negative += new_value[a][0]
            else:                         #a값이 증가하면서 new_value의 값이 0일때 카운트값 과 new_value의 첫번째 배열값 증가
                count_zero += 1
                result_zero+= new_value[a][0]
        length_list = []                 #길이를 저장하기 위한 리스트 선언
        length_list.append([result_positive, 1])
        length_list.append([result_negative, -1])
        length_list.append([result_zero, 0])
        if count_zero == count_negative == count_positive:    #-1,1,0,의 카운트가 모두 같을 때
            length_list.sort(key=lambda x: x[0])
            length_list.reverse()
            result = length_list.pop()
            result = result.pop()
        elif count_negative != count_positive != count_zero:  #-1,1,0,의 카운트가 모두 다를때
            length_list1 = []
            length_list1.append([count_zero, 0])
            length_list1.append([count_positive, 1])
            length_list1.append([count_negative, -1])
            length_list1.sort(key=lambda x: x[0])
            length_list1.reverse()
            result = length_list1.pop()
            result = result.pop()
        else:                                              #-1,1,0의 카운트가 2개만 같을때
            if count_negative == count_positive and count_negative > count_zero:   #-1과1의 카운트값이 같고 -1의 카운트값이 0의 카운트값보다 클때
                if result_negative < result_positive :    #-1일때의 배열의 결과값이 1일때의 배열의 결과값보다 클때
                    result = -1
                else :
                    result = 1
            elif count_negative == count_positive and count_negative < count_zero:  #-1과 1의 카운트값이 같고 -1의 카운트값이 0의 카운트값보다 작을때
                result = 0
            elif count_negative == count_zero and count_negative > count_positive:   #-1과 0의 카운트값이 같고 -1의 카운트값이 1의 카운트값보다 클때
                if result_negative < result_zero:     #0일때의 배열의 결과값이 -1일때의 배열의 결과값보다 클때
                    result = -1
                else:
                    result = 0
            elif count_negative == count_zero and count_negative < count_positive: #-1과 0의 카운트값이 같고 -1의 카운트값이 1의 카운트값보다 작을때
                result = 1
            elif count_positive == count_zero and count_positive > count_negative: #1과 0의 카운트값이 같고 1의 카운트값이 -1의 카운트값보다 클때
                if result_positive < result_zero:    #0일때의 배열의 결과값이 1일때의 배열의 결과값보다 클때
                    result = 1
                else:
                    result = 0
            elif count_positive == count_zero and count_positive < count_negative: #1과 0의 카운트값이 같고 1의 카운트값이 -1의 카운트값보다 작을때
                result = -1


        df.set_value(i, index3, result)

    com = 0
    i =0
    while i < (len(df.index) - 1):     #정확도값 구하기 위한 함수
        i += 1
        if df['ud_Nd'][i].item() == df[index3][i].item():
            com += 1


        aver_total = com / i * 100

    print("accuracy( K = ",k-1 ,"): ", aver_total)   #정확도 k값에 따른 출력
    #print(cities)


df = pd.read_csv('./stock_history_added.csv')



length('cv_diff_rate','cv5d_diff_rate','1nn_value', 1)    #k값이 1일때 독립변수가 cv_diff_rate와 cv5d_diff_rate일때 1nn_value의 컬럼값으로 출력
df.to_csv('stock_history_knn.csv', mode='w')
length('cv_diff_rate','cv5d_diff_rate','3nn_value', 3)    #k값이 3일때 독립변수가 cv_diff_rate와 cv5d_diff_rate일때 3nn_value의 컬럼값으로 출력
df.to_csv('stock_history_knn.csv', mode='w')
length('cv_diff_rate','cv5d_diff_rate','5nn_value', 5)  #k값이 5일때 독립변수가 cv_diff_rate와 cv5d_diff_rate일때 5nn_value의 컬럼값으로 출력
df.to_csv('stock_history_knn.csv', mode='w')
length('cv_diff_rate','cv5d_diff_rate','7nn_value', 7)  #k값이 7일때 독립변수가 cv_diff_rate와 cv5d_diff_rate일때 7nn_value의 컬럼값으로 출력
df.to_csv('stock_history_knn.csv', mode='w')
length('cv_diff_rate','cv5d_diff_rate','9nn_value', 9)  #k값이 9일때 독립변수가 cv_diff_rate와 cv5d_diff_rate일때 9nn_value의 컬럼값으로 출력
df.to_csv('stock_history_knn.csv', mode='w')
print(df)