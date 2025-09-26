<h1>Hash function - Blockchain Technologies Course</h1>
<p>This is a repository, created for my Blockchain Technologies course in university, which contains a custom hash function, written by me with no resources on how to implement one (v0.1) and improved using Claude AI (v0.2), while maintaining the original idea of the hash - using a seed derived from the UTF-8 value of the input characters to semi-randomly adjust each of the characters of a 64-character hexadecimal hash while rotating the hash between changes to ensure avalanche effect.</p>
<h2>Strengths</h2>
    <ul>
        <li>The algorithm is not collision-prone</li>
        <li>Avalanche effect is ensured - each character significantly impacts the final hash</li>
<h2>Weaknesses</h2>
    <ul>
        <li>The algorithm is very slow - hashing 100 000 strings that were 1000 symbols long took about 15 minutes</li>
        <li>The distribution is not great - numbers at the ends of the spectrum (such as 1 and 2 or E and F) appear less frequently than numbers like 8<li>
        <li>The use of a mt19937 seed generator means the hash isn't particularly secure</li>
<h2>Tests</h2>