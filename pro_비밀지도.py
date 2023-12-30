def solution(n, arr1, arr2):
    answer = ["" for _ in range(n)]
    # 이진수 만들기 -> 각 행을 or연산 시켜서 리턴하기
    for i in range(n):
        num1 = arr1[i]
        num2 = arr2[i]
        ans = num1 | num2
        ans = format(ans,'b').zfill(n)

        str=""
        for j in range(len(ans)):
            if ans[j] == "0":
                str += " "
            elif ans[j] == "1":
                str += "#"
        answer[i]=str

    return answer