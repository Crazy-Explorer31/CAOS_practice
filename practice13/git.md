1. Локальный репозиторий:
	* создать локальный репозитарий: `git init`
	* добавить файл в индекс: `git add file.c`
	* удалить файл: `git rm file.c`
	* посмотреть разницу между рабочей копией и репозиторием: `git diff`, `git difftool --tool=meld` (meld -- отдельная программа)
	* посмотреть состояние (что включено в индекс, что изменено) рабочей копии: `git status`
	* создать коммит в репозиторий: `git commit -m "Commit message"`
	* дополнить коммит новыми файлами: `git commit --amend`
	* посмотреть историю изменений в репозитории: `git log`, `git log --oneline`, `git log --graph`, `gitk` (отдельная программа)
	* отменить последний коммит, но файлы из него сохранить в индексе: `git reset --soft`
	* удалить последний коммит: `git reset --hard`
	* перейти на коммит с commit_id: `git checkout commit_id`
2. Стратегии слияния веток (`master` и `feature`):
	* создать ветку с именем branch и на нее перейти: `git checkout -b branch`
	* выполнить rebase с ветки from на ветку to: `git rebase from to`
	* выполнить merge ветки from и текущей ветки: `git merge from`
	* merge: создается новый коммит (так называемый `merge commit`), имеющий два предка коммит из `feature` и коммит из `master`.
	* rebase: все коммиты с ветки `feature` применяются к ветке `master` после точки разделения, за ними к ветке `master` применяются новые коммиты  из `master`
	* интерактивный rebase, возможность полностью переписать историю изменений от commit_id: `git rebase -i commit_id` (squash, change, edit, delete)
	* взять коммит с commit_id и добавить в текущую ветку: `git cherry-pick commit_id`
3.	Конфликты
   * в двух разных ветках (feature и master) меняется одна и та же строка в файле main.cpp
   * `git rebase feature master`
   * вручную отредактировать до корректного состояния main.cpp (git _все равно_ на финальное содержимое файла)
   * `git add main.cpp` (сказать git, что конфликт разрешен)
   * `git rebase --continue`
4. Внешний репозиторий:
	* склонировать себе внешний репозиторий (origin) с адреса url: `git clone url`
	* забрать изменения из внешнего репозитория со стратегией rebase: `git pull --rebase`
	* послать изменения во внешний  репозиторий: `git push origin local_branch:server_branch` (например, `git push origin main:test`, локальная ветка main, удаленная ветка test)
	* удалить ветку во внешнем репозитории: `git push origin -d branch-name`
