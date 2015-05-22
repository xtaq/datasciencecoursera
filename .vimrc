set nocompatible
set encoding=utf-8  
set fenc=utf-8  
set fileencodings=ucs-bom,utf-8,cp936,gb2312,gb18030,big5 
set history=100

set hlsearch
set cursorline
set laststatus=2
set ts=4
set backspace=2
set autoindent
set ruler
set showmode
set nu
set bg=dark
syntax on
set cindent
set smartindent
filetype on
call pathogen#infect()

"powerline{
set guifont=PowerlineSymbols\ for\ Powerline
set nocompatible
set t_Co=256
let g:Powerline_symbols = 'fancy'
"}

"taglist{
let Tlist_Show_One_File = 1           
let Tlist_Exit_OnlyWindow = 1          
let Tlist_Use_Right_Window = 1         
let Tlist_GainFocus_On_ToggleOpen = 1 
let Tlist_Ctags_Cmd='/usr/local/bin/ctags'
nnoremap <leader>tl : Tlist<CR>        
"}

filetype plugin indent on

let g:pydiction_location='/Users/xt/.vim/bundle/pydiction/complete-dict'

let g:pydiction_menu_height=20

map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR> 

map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
    if &filetype == 'c'
        exec "!g++ % -o %<"
        exec "! ./%<"
    elseif &filetype == 'cpp'
        exec "!g++ % -o %<"
        exec "! ./%<"
	elseif &filetype == 'java' 
		exec "!javac %"
		exec "!java %<"
	elseif &filetype == 'sh'
		:!./%
	elseif &filetype == 'py'
		exec "!python %"
	endif
endfunc

map <F3> :NERDTree <CR>
