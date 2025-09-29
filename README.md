<h1>Hash function - Blockchain Technologies Course</h1>
<p>This is a repository, created for my Blockchain Technologies course in university, which contains a custom hash function, written by me with no resources on how to implement one (v0.1) and improved using Claude AI (v0.2), while maintaining the original idea of the hash - using a seed derived from the UTF-8 value of the input characters to semi-randomly adjust each of the characters of a 64-character hexadecimal hash while rotating the hash between changes to ensure avalanche effect.</p>
<h3>Strengths</h3>
    <ul>
        <li>The algorithm is not collision-prone</li>
        <li>Avalanche effect is ensured - each character significantly impacts the final hash, even more than my original hash (see v0.1)</li>
        <li>Significantly faster than my original hash (see v0.1)</li>
    </ul>
<h3>Weaknesses</h3>
    <ul>
        <li>The mixing approach Claude implemented uses several mathematical and bit operations I wouldn't be able to recreate myself </li>
    </ul>
<h3>Tests</h3>
<img width="936" height="838" alt="Screenshot of AI improved code tests" src="https://github.com/user-attachments/assets/ac002aa3-47d8-471a-a2b7-56dd5c0cd8b1" />
