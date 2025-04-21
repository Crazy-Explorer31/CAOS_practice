* Phy/Data-Link Layer: packet, MTU (1500), передача point-to-point
    * преобразовать 0/1 в сигналы среды
    * исправление ошибок
        ```
        0001001 0
        1001001 0 detected
        1101001 0 not detected
        ```
    * одновременный доступ к среде: послал, не получил подтверждения, выждал случайное время, послал еще раз
    * MAC: 48 bit
    * `[MAC_DST, MAC_SRC, Data]`
    * IEEE: WiFi (802.11), Ethernet (802.3)

* Network Layer
    * `[MAC_DST, MAC_SRC, IP_DST, IP_SRC, Data]`
       ```
       IP1              IP2
       * --- * ---* --- *
       M1    M2   M3    M4
              |
              ---* IP3
                 M5
       ```
   * [M2, M1, IP2, IP1, Data]
   * [M3, M2, IP2, IP1, Data]
   * [M4, M3, IP2, IP1, Data]

* Transport
   * `[MAC_DST, MAC_SRC, IP_DST, IP_SRC, PORT_SRC, PORT_DST, Data]`

   ```
   IP1              IP2
   * --- * ---* --- *
   M1    M2   M3    M4
          |         |
          ---* --- *IP3
   ```
   *  [3][2][1]  --> [3][1][2]
   * UDP
      * нет гарантии доставки: доставлено/точно знаю, что не доставлено
      * нет гарантии порядка
      * нет фрагментации
   * TCP
      ```
      IP1 IP2
      |.  |
      | . |
      |  .|
      |  *|
      | * |
      |*  |
      |.  |
      | . |
      |  .|
      |  *|
      | * |
      |*  |
      ```
* Application
   * HTTP

* Команды:
   * `ip link` показать MAC адреса
   * `ip a` показать IP адреса
   * `getaddinfo example.com 80`
   * `socket_example example.com 80`


