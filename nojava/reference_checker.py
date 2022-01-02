from dmoj.result import CheckerResult
import math

def check(proc_output, judge_output, judge_input, point_value, submission_source, **kwargs):
    try:
        user_answer = proc_output.strip()
        rating = int(user_answer)
        if rating == 100:
            return CheckerResult(False, 0, "Liar! No contest is perfect!")
        elif rating == 0:
            return CheckerResult(False, 0, "Thank you for your honest feedback.")
        elif rating > 0 and rating < 100:
            return CheckerResult(True, math.ceil(rating / 5.0) * 5, "Thank you for your honest feedback.")
        else:
            return CheckerResult(False, 0, "Response rejected: bad format")
    except Exception:
        return CheckerResult(False, 0, "Response rejected: bad format")
