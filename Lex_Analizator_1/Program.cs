using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CleanConsole
{
    internal struct Lexem
    {
        public readonly int Id;
        public readonly string Value;

        public Lexem(int id, string value)
        {
            Id = id;
            Value = value;
        }
    }

    internal static class LexicalAnalyzer
    {
        private static List<string> InitializePatterns()
        {
            var patterns = new List<string>();
            patterns.Add(@"\d+(?![\,\d])");
            patterns.Add(@"\d+\,\d+");
            patterns.Add(@"[\+\-\s*/]");
            patterns.Add(@"[_a-zA-Z][_a-zA-Z0-9]*");
            return patterns;
        }

        private static string WrapInParentheses(string s)
        {
            return @"(" + s + @")";
        }

        private static Regex BuildRegex(List<string> patterns)
        {
            var pattern = new StringBuilder();
            pattern.Append(@"\G(?:");
            pattern.Append(patterns.Select(WrapInParentheses).Aggregate((a, b) => a + "|" + b));
            pattern.Append(@")");
            return new Regex(pattern.ToString());
        }

        private static readonly Regex ReadyRegex = BuildRegex(InitializePatterns());

        public static IEnumerable<Lexem> Parse(string text)
        {
            var matches = ReadyRegex.Matches(text);
            int lastIndex = 0;
            foreach (Match match in matches)
            {
                var capture = match.Captures.Cast<Capture>().First();
                int id = RetrieveId(match);
                string value = capture.Value;
                yield return new Lexem(id, value);
                lastIndex = capture.Index + capture.Length;
            }
            if (lastIndex != text.Length)
                throw new InvalidOperationException("Непридусмотренный Конец Текста, мяу)");
        }

        private static int RetrieveId(Match match)
        {
            for (int i = 1; true; ++i)
                if (match.Groups[i].Success)
                    return i;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            string text = Console.ReadLine() ?? "";
            var lexems = LexicalAnalyzer.Parse(text);
            foreach (var lexem in lexems)
            {
                Console.WriteLine(lexem.Id + " " + lexem.Value);
            }
        }
    }
}