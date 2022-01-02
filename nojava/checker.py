from dmoj.result import CheckerResult

def check(process_output, judge_output, judge_input, point_value, submission_source, **kwargs):
    try:
        if "java".encode() in submission_source:
            return CheckerResult(False, 0, "Java was not removed")
        if process_output != judge_output:
            return CheckerResult(False, 0, "Wrong Answer")
        return CheckerResult(True, 100, "Pass")
    except Exception as e:
        return CheckerResult(False, 0, "Response rejected")
