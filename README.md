<h1>Hash function - Blockchain Technologies Course</h1>
<h2>About the algorithm</h2>
<p>This is a repository, created for my Blockchain Technologies course in university, which contains a custom hash function, written by me with no resources on how to implement one (v0.1) and improved using Claude AI (v0.2), while maintaining the original idea of the hash - using a seed derived from the UTF-8 value of the input characters to semi-randomly adjust each of the characters of a 64-character hexadecimal hash while rotating the hash between changes to ensure avalanche effect.</p>
<h3>Strengths</h3>
    <ul>
        <li>The algorithm is not collision-prone</li>
        <li>Avalanche effect is ensured - each character significantly impacts the final hash</li>
    </ul>
<h3>Weaknesses</h3>
    <ul>
        <li>The algorithm is very slow - hashing 100 000 strings that were 1000 symbols long took about 15 minutes</li>
        <li>The distribution is not great - numbers at the ends of the spectrum (such as 1 and 2 or E and F) appear less frequently than numbers like 8</li>
        <li>The use of a mt19937 seed generator means the hash isn't particularly secure</li>
    </ul>
<h2>Setup</h2>
<h3>Setup guide using make</h3>
<ol>
    <li><a href="https://codefinity.com/blog/A-step-by-step-guide-to-Git-installation?utm_source=google&utm_medium=cpc&utm_campaign=21413601262&utm_content=&utm_term=&dki=&gad_source=1&gad_campaignid=21409590893&gbraid=0AAAAABTeUgSZ7Ulz-l3XpMFdKumiEbn1r&gclid=CjwKCAjw_-3GBhAYEiwAjh9fUGsC8VLlpsHRSPLBB7AHe0LuNQK0RmGwhNuy7P4KjUFxwQMkV505rRoCz8YQAvD_BwE">Install git</a> and <a href="https://medium.com/@AliMasaoodi/installing-make-on-windows-10-using-chocolatey-a-step-by-step-guide-5e178c449394">make</a></li>
    <li><a href="https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository">Clone this repository</a></li>
    <li>Open the command prompt on your computer</li>
    <li>Navigate to the directory you cloned this repository into
    <li>Type "make" into your command prompt to build the project</li>
    <li>Type "make run" into your command prompt to run the program - this will allow you to input the text you want to hash manually.</li>
</ol>
<p> Instead of step 6, you can also run the program by typing "hashFunction.exe" into the command prompt, followed by the path and name of any file you want the program to hash - this will essentially skip the input function and read from a file instead.</p>

<h3>Setup guide for tests</h3>
<ol>
    <li>Follow steps 1-4 of the first setup guide</li>
    <li>Type "make tests" into the command prompt</li>
</ol>
<p>The tests use testing files which come with the code - they are located in the 'files' folder. You can change the content of these files if you'd like, but do not change the names or delete files - they are hardcoded into the tests :)</p>

<h2>Testing</h2>
<img width="900" alt="My hash and SHA256 comparison tests" src="https://github.com/user-attachments/assets/c3e1fc46-b0d3-4d86-92f3-b90688c06bf1" />
<img width="900" alt="My hash and SHA256 comparison tests" src="https://github.com/user-attachments/assets/7104f802-8382-4f30-94f2-8a52bd8ae0de" />

<p></p>
<p> As seen in the speed tests, doubling the size of the input roughly doubles the duration of hashing, proving that the algorithm's time complexity is linear - O(n), even if it isn't particularly efficient.</p>

<h2>Conclusions</h2>
<ul>
    <li>Using a mt19937 generator for seeded randomizing is not a very good way to create a hash algorithm, as it is quite slow and pretty predictable.</li>
    <li>While AI improved my hash function in several ways, it was very hard to get it to stick to my idea of the code, as it kept trying to change it to behave more like one of the more widely used hashing functions.</li>
    <li>Ultimately, while building a custom hash function is a great learning experience, making something that will outperform standards like SHA256 and MD5 in any way is nearly impossible, especially if you are doing with no prior understanding or resources on hash functions.</li>
</ul>
