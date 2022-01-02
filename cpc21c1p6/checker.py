from dmoj.result import CheckerResult

def check(process_output, judge_output, judge_input, point_value, submission_source, **kwargs):
    try:
        res = list(map(int, process_output.decode("utf-8").strip().split()))
        ans = list(map(int, judge_output.decode("utf-8").strip().split()))

        assert len(res) == len(ans)
        ok = sum(res) == sum(ans)

        if ok:
            all = judge_input.decode("utf-8").strip().split('\n')
            n = int(all[0])
            for i in range(1, n+1):
                a = list(map(int, all[i].strip().split()))
                if a[0] < ans[0] and a[1] < ans[1] and a[2] < ans[2]:
                    ok = False
                    break
        
        if not ok:
            return CheckerResult(False, 0, "Wrong Answer")
        return CheckerResult(True, point_value, "Pass")
    except Exception as e:
        return CheckerResult(False, 0, "Presentation Error")

