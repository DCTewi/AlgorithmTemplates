" Vim Configuration File
" Author: dctewi@dctewi.com
" Description: For minimal icpc use
"

" System Detect
if !exists("g:os")
    if has("win64") || has("win32") || has("win16")
        let g:os = "win"
    else
        let g:os = "unix"
    endif
endif

" Properties
set nocompatible
set showcmd
set mouse=a
set backspace=2
set encoding=utf-8
set t_Co=256
filetype indent on
if g:os == "win"
  set clipboard=unnamed
else
  set clipboard=unnamedplus
endif

" Util
set noswapfile
set noerrorbells
set autoread

" Indent
set cindent
set tabstop=4
set shiftwidth=4
set expandtab
set softtabstop=4

" Layout
syntax enable
syntax on
set number
set cursorline
set showmatch
hi MatchParen cterm=bold ctermbg=none ctermfg=blue

" Search
set hlsearch
set incsearch
set ignorecase
set smartcase

" Compile
if g:os == "win"
    map <F5> :w <CR> :!g++ "%" -o "%<.exe" -std=c++14 -O2 -Wall -DDEBUG ; "./%<.exe" <CR>
else
    map <F5> :w <CR> :!g++ "%" -o "%<.exe" -std=c++14 -O2 -Wall -DDEBUG && "./%<.exe" <CR>
endif
map <C-F5> :w <CR> :!python3 % <CR>

" Auto complete
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O

" Header
inoremap <F8> #include<bits/stdc++.h><CR>using namespace std;<CR>typedef long long ll;<CR>

" GVim
if has("gui_running")
    set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
    set fileencoding=utf-8
    set guioptions-=m
    set guioptions-=T
    set guioptions-=r
    set lines=35 columns=120
    colorscheme torte
    if g:os == "win"
        set guifont=Microsoft_Yahei_Mono:h11
    else
        set guifont=Fira\ Mono\ 12
    endif
endif

