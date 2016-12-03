Submission Guidelines

Submitting an Issue

Before you submit your issue search the archive, maybe your question was already answered.

If your issue appears to be a bug, and hasn't been reported, open a new issue. Help us to maximize the effort we can spend fixing issues and adding new features, by not reporting duplicate issues. Providing the following information will increase the chances of your issue being dealt with quickly:

Overview of the Issue - if an error is being thrown a non-minified stack trace helps
Motivation for or Use Case - explain why this is a bug for you
Angular Version(s) - is it a regression?
Browsers and Operating System - is this a problem with all browsers or only specific ones?
Reproduce the Error - provide a live example (using Plunker or JSFiddle) or an unambiguous set of steps.
Related Issues - has a similar issue been reported before?
Suggest a Fix - if you can't fix the bug yourself, perhaps you can point to what might be causing the problem (line of code or commit)
Here is a great example of a well defined issue: https://github.com/angular/angular.js/issues/5069

If you get help, help others. Good karma rulez!

Submitting a Pull Request

Before you submit your pull request consider the following guidelines:

Search GitHub for an open or closed Pull Request that relates to your submission. You don't want to duplicate effort.
Please sign our Contributor License Agreement (CLA) before sending pull requests. We cannot accept code without this.
Make your changes in a new git branch:

git checkout -b my-fix-branch master
Create your patch, including appropriate test cases.

Follow our Coding Rules.
Run the full Angular test suite, as described in the developer documentation, and ensure that all tests pass.
Commit your changes using a descriptive commit message that follows our commit message conventions and passes our commit message presubmit hook (validate-commit-msg.js). Adherence to the commit message conventions is required, because release notes are automatically generated from these messages.

  git commit -a
Note: the optional commit -a command line option will automatically "add" and "rm" edited files.

Build your changes locally to ensure all the tests pass:

grunt test
Push your branch to GitHub:

git push origin my-fix-branch
In GitHub, send a pull request to angular:master. If we suggest changes, then:

Make the required updates.
Re-run the Angular test suite to ensure tests are still passing.
Commit your changes to your branch (e.g. my-fix-branch).
Push the changes to your GitHub repository (this will update your Pull Request).
If the PR gets too outdated we may ask you to rebase and force push to update the PR:

git rebase master -i
git push origin my-fix-branch -f
WARNING: Squashing or reverting commits and force-pushing thereafter may remove GitHub comments on code that were previously made by you or others in your commits. Avoid any form of rebasing unless necessary.

That's it! Thank you for your contribution!
