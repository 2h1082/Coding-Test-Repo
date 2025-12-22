# [Platinum III] Ecologia - 13614 

[문제 링크](https://www.acmicpc.net/problem/13614) 

### 성능 요약

메모리: 2216 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 브루트포스 알고리즘, 정렬, 애드 혹, 집합과 맵, 누적 합, 비트마스킹, 해시를 사용한 집합과 맵, 비트필드를 이용한 다이나믹 프로그래밍, 재귀, 비트 집합

### 제출 일자

2025년 12월 22일 17:26:20

### 문제 설명

<p>O reino da Poliminogônia passou recentemente uma lei ecológica que obriga todas as fazendas a preservar o máximo de árvores possível em uma porcentagem fixa da área da fazenda. Além disso, para que os animais silvestres possam se movimentar livremente, a área preservada deve ser conexa. </p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13614/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-05%20%EC%98%A4%ED%9B%84%206.55.41.png" style="height:137px; width:137px"></p>

<p>As fazendas na Poliminogônia são sempre um reticulado de N × N quadrados de um hectare cada. A figura ao lado ilustra uma fazenda com N = 5. A área preservada deve cobrir exatamente M quadrados. No exemplo da figura, M = 6. Ela deve ser conexa ortogonalmente; quer dizer, tem que ser possível se movimentar entre quaisquer dois quadrados preservados apenas com movimentos ortogonais entre quadrados preservados. A área não preservada, entretanto, pode ser desconexa.</p>

<p>Os fazendeiros sabem o número de árvores que há dentro de cada quadrado e você deve escrever um programa que calcule o número máximo possível de árvores que podem ser preservadas com uma area de M quadrados. No exemplo, é possível preservar 377 árvores!</p>

### 입력 

 <p>A primeira linha da entrada contém dois inteiros N e M (2 ≤ N ≤ 50, 1 ≤ M ≤ 10). As N linhas seguintes contêm, cada uma, N inteiros de valor entre 1 e 1000, representando o número de árvores dentro de cada quadrado da fazenda.</p>

<p> </p>

### 출력 

 <p>Seu programa deve imprimir uma linha contendo um número inteiro, o número máximo de árvores que podem ser preservadas, com as restrições dadas.</p>

