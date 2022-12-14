## git Installation
-   Components
    -   default
-   Default editior
    -   VScode
-   Name for initial branch
    -   mster
-   Path environment
    -   git from the command line (recommanded)
-   Use bubdled OpenSSH
-   Check out Widnows-style, commit Unix-style
-   Use MindTTY
-   Rebase
-   None (maybe Git Credential Manager)
-   no Symblic link
-   no experimental

## New repository
-   git init: to initialize a repo
-   echo . > README.md or echo " " > README.md (touch README.md for Windows)
-   type .\README.md
-   git status to check commits
-   git pull
-   git add .\README.md
-   git echo " " > .\README.md

-   git checkout .\README.md
-   git commit

-   git config --global user.name "Name"
-   git config --global user.email "name@email.com"

-   git config --global pull.rebase true

## Demo git diff
-   git status
-   git diff
-   git commit -am "msg"
-   git commit -a // add and commit modified files but not untracked files

## Demo branch
-   git branch branchname // add new branch
-   git branch // to show all branch
-   git checkout branchname // to switch to different branch
-   git commit on branch2 does not affect branch1

-   branch1
-   branch2
-   git commit at branch2
-   want to merge from branch2 to branch1
-   git merge branch2

-   git checkout -b branch3
-   git checkout branch
-   git checkout branch2
-   git branch -d branch3

-   goes back to previous commit
-   git reset --hard lognumber

-   git checkout branch1
-   git branch -d branch2

-   Generatte ssh key
-   ssh-keygen
-   cd
-   ls
-   cd .ssh
-   ls
-   type id_rsa.pub

-   git remote add origin git@github.com/name/repository
-   git remote
-   git remote -v

-   git push -u origin(remote) master(local branch)
-   git pull

-   git branch -d branch1 // delete a branch at local
-   git push origin -d branch1 // delete a branch at remote
