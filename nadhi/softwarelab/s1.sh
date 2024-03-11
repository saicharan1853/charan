# Task 1: Create Folder and Text File
mkdir Inf43Hw2
cd Inf43Hw2
echo "saicharan BT22CSE107" > file1.txt

#C:/Users/saich/nadhi/softwarelab/Inf43Hw2/.git/

# 3
git config --global user.name "saicharan"
git config --global user.email "saicharanramavath41@gmail.com"
#4
git init

# Task 5-8: Add and Commit file1.txt
#5
git status
git add file1.txt
#6
git status
#7
git commit -m "Committing a new file with my name"
#8
git log #enter q to exit

# Task 9-10: Undo Changes with git reset --hard
#9
nano file1.txt  # Edit the file (change your name)
#10
git reset --hard
cat file1.txt #pirnting contents of file1.txt

# Task 11-16: Edit and Amend Commits
#11
nano file1.txt  # Edit the file (remove student ID, add the name of your major)
#12
git commit -m "Now has my major" #git tells you that no changes added to commit
#13
git commit -a -m "Now has my major"
#14
nano file1.txt  # Add favorite restaurant and movie
git add file1.txt
git commit -m "Added favorite restaurant"

#15
git commit --amend -m "Added favorite restaurant and movie"

# Task 17-19: Go Back in Time
#16
git log  # Find the commit hash
#17&18
git checkout a414 # first four digits of the hash and we willbe in that branch
#19
git checkout master  # Return to the master branch

# Task 20-29: Add and Remove file2.txt
#20
echo "2026 software engineer" > file2.txt
#21
git add file2.txt
git commit -m "Adding file2.txt with graduation year and job title"
#22
git log
#23
git log file2.txt
#24
nano file1.txt  # Modify file1.txt (add favorite color)
#25
git rm file2.txt
#26
git status 
#27
git add file1.txt
git rm file2.txt
#28
git commit -m "Deleting file2.txt"
#29
git log -p -3

# Task 30-33: Restore file2.txt
#30
git checkout HEAD~1 file2.txt
#31
git add file2.txt
#32
git status
git commit -m "Re-adding file2.txt"
#33
git log -p
#34
git log -p > git_log_partB.txt
#35
#open the git_log_partB.txt file
#36

# Task 36: Push to GitHub
git remote -v #to check the remote repo
git remote add origin https://github.com/saicharan1853/charan.git
git branch -M main  # If not using master branch
git fetch origin
git pull origin main # git pull origin main --allow-unrelated-histories
git add .
git commit -m "Resolved merge conflicts."
git push -u origin main
git fetch origin main
git checkout main
git merge --allow-unrelated-histories origin/main
