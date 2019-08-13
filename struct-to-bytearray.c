#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



struct Order {
        uint64_t order_id;
        uint8_t quantity;
        char part_number[16];
        char *email_address;
};

struct OrderBatch {
        uint64_t id;
        uint64_t timestamp;
        uint16_t order_cnt;
        struct Order *orders;
};

uint64_t reverse64(uint64_t data)
{
        uint64_t b0, b1, b2, b3;
        b0 = ((data << 56) & 0xff00000000000000) | ((data >> 56) & 0x00000000000000ff);
        b1 = ((data << 40) & 0x00ff000000000000) | ((data >> 40) & 0x000000000000ff00);
        b2 = ((data << 24) & 0x0000ff0000000000) | ((data >> 24) & 0x0000000000ff0000);
        b3 = ((data << 8) & 0x0000000ff0000000) | ((data >> 8) & 0x0000000000ff0000);

        return ( b0 | b1 | b2 | b3);
}

uint32_t reverse32(uint32_t data)
{
        uint32_t b0, b1;

        b0 = ((data << 24) & 0xff000000) | ((data >> 24) & 0x000000ff);
        b1 = ((data << 8) & 0x00ff0000) | ((data >> 8) & 0x00000ff00);

        return (b0 | b1);
}

uint16_t reverse16(uint16_t data)
{
        uint16_t b0;

        b0 = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff);

        return b0;
}

int serialize_order(struct OrderBatch *order, size_t *len, uint8_t *out)
{
        int i, k = 0;
        uint64_t id, timestamp, order_id;
        uint16_t order_cnt;
        uint8_t *orig_out = out;

        *len = sizeof(order->id) + sizeof(order->timestamp) + sizeof(order->order_cnt);
        for (i = 0; i < order->order_cnt; i++) {
                *len += sizeof(order->orders[i].order_id) + sizeof(order->orders[i].quantity) + sizeof(order->orders[i].part_number) + strlen(order->orders[i].email_address) + 1;
        }
        printf("len = %ld\n", *len);
        id = reverse64(order->id);
        memcpy(&out[k], (uint8_t *)&id, sizeof(id));
        k += sizeof(id);
        timestamp = reverse64(order->timestamp);
        memcpy(&out[k], (uint8_t *)&timestamp, sizeof(timestamp));
        k += sizeof(timestamp);
        order_cnt = reverse16(order->order_cnt);
        memcpy(&out[k], (uint8_t *)&order_cnt, sizeof(order_cnt));
        k +=  sizeof(order_cnt);

        for (i = 0; i < order->order_cnt; i++) {
                order_id = reverse64(order->orders[i].order_id);
                memcpy(&out[k], (uint8_t *)&order_id, sizeof(order_id));
                k += sizeof(order_id);
                memcpy(&out[k], (uint8_t *)&order->orders[i].quantity, sizeof(order->orders[i].quantity));
                k += sizeof(order->orders[i].quantity);
                memcpy(&out[k], order->orders[i].part_number, sizeof(order->orders[i].part_number));
                k += sizeof(order->orders[i].part_number);
                memcpy(&out[k], order->orders[i].email_address, strlen(order->orders[i].email_address) + 1);
                k += strlen(order->orders[i].email_address) + 1;
        }

        return 0;
}

int main()
{
        int i;
        size_t len;
        uint8_t out[1024];
        char email1[] = "esde@amazon.com";
        char email2[] = "esde@amazon2.com";
        char part_number1[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        char part_number2[16] = {'a', 'b', 'c', 'd', 'e', 'f', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        struct OrderBatch order;

        memset(&order, 0, sizeof(order));
        memset(out, 0, sizeof(out));
        order.id = 0x5;
        order.timestamp = 0x65;
        order.order_cnt = 0x2;
        order.orders = (struct Order *)malloc(sizeof(struct Order)*order.order_cnt);
        memset(order.orders, 0, sizeof(struct Order)*order.order_cnt);
        order.orders[0].order_id = 0x1;
        order.orders[0].quantity = 0x9;
        memcpy(order.orders[0].part_number, part_number1, 16);
        order.orders[0].email_address = (char *)malloc(strlen(email1)+1);
        memset(order.orders[0].email_address, 0, strlen(email1)+1);
        strncpy(order.orders[0].email_address, email1, strlen(email1)+1);

        order.orders[1].order_id = 0x2;
        order.orders[1].quantity = 0x8;
        memcpy(order.orders[1].part_number, part_number2, 16);
        order.orders[1].email_address = (char *)malloc(strlen(email2)+1);
        memset(order.orders[1].email_address, 0, strlen(email2)+1);
        strncpy(order.orders[1].email_address, email2, strlen(email2)+1);

        serialize_order(&order, &len, out);
        for (i = 0; i < len; i++) {
                printf("%02x ", out[i]);
        }
        printf("\n");

        return 0;
}
