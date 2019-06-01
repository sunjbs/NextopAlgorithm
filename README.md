# Nextop Algorithm

| 문제 이름(채점 링크) | 파일 이름 |
| ----------------- | ------ |
| [화살표 그리기](https://www.acmicpc.net/problem/15975) | [draw_arrow1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/draw_arrow1.cpp), [draw_arrow2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/draw_arrow2.cpp) |
| [관중석](https://www.acmicpc.net/problem/10166) | [stand1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/stand1.cpp), [stand2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/stand2.cpp) |
| [두 박스](https://www.acmicpc.net/problem/15973) | [two_boxes1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/two_boxes1.cpp), [two_boxes2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/two_boxes2.cpp) |
| [행복](https://www.acmicpc.net/problem/15969) | [happiness.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/happiness.cpp) |
| [물통](https://www.acmicpc.net/problem/14867) | [bottle1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/bottle1.cpp) |
| [수 정렬하기](https://www.acmicpc.net/problem/2750) | [num_sort.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/num_sort.cpp) |
| [수 정렬하기2](https://www.acmicpc.net/problem/2751) | [num_sort2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/num_sort2.cpp) |
| [수 정렬하기3](https://www.acmicpc.net/problem/10989) | [num_sort3.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/num_sort3.cpp)|
| [DFS와 BFS](https://www.acmicpc.net/problem/1260) | [DfsAndBfs.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/DfsAndBfs.cpp) | 
| [방 배정하기](https://www.acmicpc.net/problem/14697) | []() |
| [딱지놀이](https://www.acmicpc.net/problem/14696) | []() |
| [리조트](https://www.acmicpc.net/problem/13302) | []() |
| [방배정](https://www.acmicpc.net/problem/13304) | []() |

## 자료구조

| 자료구조 | 참고 |
| ------ | ---- |
| 그래프 | graph.c 참고 |

## 연습

| 문제 이름(채점 링크) | 풀이 링크 |
| ----------------- | ------ |
| [약수 구하기](https://www.acmicpc.net/problem/2501) | [풀이 및 코드](https://dochi3.tistory.com/18?category=685514) |
| [카드 역배치](https://www.acmicpc.net/problem/10804) | [풀이 및 코드](https://dochi3.tistory.com/19?category=685514) |
| [가로수](https://www.acmicpc.net/problem/2485) | [풀이 및 코드](https://dochi3.tistory.com/20?category=685514) |
| [토마토](https://www.acmicpc.net/problem/7569) | [풀이 및 코드](https://dochi3.tistory.com/21?category=685514) |
| [놀이공원](https://www.acmicpc.net/problem/2594) | [풀이 및 코드](https://dochi3.tistory.com/22?category=685514) |

## 수학문제 참조 동영상

- [2017년 정보 올림피아드 고등부 지역예선 1번 ~ 5번](https://youtu.be/5laxJD1yp8A?list=UUjGIi1SFMH3wmTDkjEHSXhQ)
- [2017년 정보 올림피아드 고등부 지역예선 6번 ~ 10번](https://youtu.be/QCYOcnhuH20?list=UUjGIi1SFMH3wmTDkjEHSXhQ)
- [2017년 정보 올림피아드 고등부 지역예선 11번 ~ 15번](https://youtu.be/piqKnjvDpTs?list=UUjGIi1SFMH3wmTDkjEHSXhQ)

## cin, cout 속도 줄이기
``` c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

## 출력이 많은 경우

c++의 경우 줄바꿈을 위하여 endl을 사용하는 것보다 '\n'을 사용하는 것이 더욱 빠르다.

```c++
// 변수 answer를 10만번 출력하는 경우
for(int i = 0; i < n; i++){
    // 정답을 구하기 위한 코드
    ...
    
    // endl 보다 '\n'이 실행시간이 빠르다
    // cout << answer << endl;
    cout << answer << '\n';
}
```