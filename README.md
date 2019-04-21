# Nextop Algorithm

| 문제 이름(채점 링크) | 파일 이름 |
| ----------------- | ------ |
| [화살표 그리기](https://www.acmicpc.net/problem/15975) | [draw_arrow1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/draw_arrow1.cpp), [draw_arrow2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/draw_arrow2.cpp) |
| [관중석](https://www.acmicpc.net/problem/10166) | [stand1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/stand1.cpp), [stand2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/stand2.cpp) |
| [두 박스](https://www.acmicpc.net/problem/15973) | [two_boxes1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/two_boxes1.cpp), [two_boxes2.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/two_boxes2.cpp) |
| [행복](https://www.acmicpc.net/problem/15969) | [happiness.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/happiness.cpp) |
| [물통](https://www.acmicpc.net/problem/14867) | [bottle1.cpp](https://github.com/sunjbs/NextopAlgorithm/blob/master/src/bottle1.cpp) |
| [방 배정하기](https://www.acmicpc.net/problem/14697) | []() |
| [딱지놀이](https://www.acmicpc.net/problem/14696) | []() |
| [리조트](https://www.acmicpc.net/problem/13302) | []() |
| [방배정](https://www.acmicpc.net/problem/13304) | []() |


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