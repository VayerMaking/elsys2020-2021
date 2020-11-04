
import unittest
import solution


class SolutionTest(unittest.TestCase):
    def setUp(self):
        self.logs = [
            {
                "timestamp": "2020-05-11T13:42:50",
                "status": "error",
                "countryISO2": "BG"
            },
            {
                "timestamp": "2020-05-11T13:43:20",
                "status": "success",
                "countryISO2": "UK"
            },
            {
                "timestamp": "2020-05-11T13:44:30",
                "status": "success",
                "countryISO2": "NZ"
            },
        ]

    def test_filter_logs_returns_all_matching_logs(self):
        res = solution.filter_logs(self.logs, 'status', 'error')
        self.assertEqual([self.logs[0]], res)

        res = solution.filter_logs(self.logs, 'status', 'success')
        self.assertEqual([self.logs[1], self.logs[2]], res)

    def test_filter_logs_returns_empty_list_if_no_matchings_found(self):
        res = solution.filter_logs(self.logs, 'status', 'no_status')
        self.assertEqual([], res)

    def test_top_returns_top_one_result(self):
        res = solution.top(self.logs, 'status', 1)
        self.assertEqual({'success': 2}, res)

    def test_top_returns_multiple_results_in_correct_order(self):
        res = solution.top(self.logs, 'status', 2)
        self.assertEqual({'success': 2, 'error': 1}, res)

    def test_top_returns_all_matchings_if_N_is_bigger_than_count_of_logs(self):
        res = solution.top(self.logs, 'status', 100)
        self.assertEqual({'success': 2, 'error': 1}, res)

    def test_complex_filter_with_one_param(self):
        res = solution.complex_filter(
            self.logs, {"status": "error"})
        self.assertEqual([self.logs[0]], res)

    def test_complex_filter_with_multiple_params(self):
        res = solution.complex_filter(
            self.logs, {"status": "success", "countryISO2": "NZ"})
        self.assertEqual([self.logs[2]], res)

    def test_complex_filter_returns_empty_list_if_no_params_match(self):
        res = solution.complex_filter(
            self.logs, {"status": "error", "countryISO2": "UK"})
        self.assertEqual([], res)

    def test_complex_filter_returns_all_logs_if_no_params_are_given(self):
        res = solution.complex_filter(
            self.logs, {})
        self.assertEqual(self.logs, res)


if __name__ == "__main__":
    unittest.main()
