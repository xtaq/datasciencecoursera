ctags --recurse --tag-relative \
    --languages=-javascript,sql \
    --exclude=.git \
    --sort=yes --append \
    --PHP-kinds=+cf \
    --regex-PHP='/abstract class ([^ ]*)/\1/c/' \
    --regex-PHP='/interface ([^ ]*)/\1/c/' \
    --regex-PHP='/(public |static |abstract |protected |private )+ *function *([^ (]*)/\2/f/' \
    --regex-php='/^[ \t]*trait[ \t]+([a-z0_9_]+)/\1/t,traits/i'
