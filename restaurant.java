import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface MenuItems {
    String getName();

    String getDescription();

    double getPrice();
}

class RestaurantMenuItem implements MenuItems {
    private String name;
    private String description;
    private double price;

    // Constructor
    public RestaurantMenuItem(String name, String description, double price) {
        this.name = name;
        this.description = description;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public double getPrice() {
        return price;
    }

}

interface Order {
    void add_item_to_order(RestaurantMenuItem item);

    void remove_item_from_order(RestaurantMenuItem item);

    double calculateTotalPrice();
}

class RestaurantOrder implements Order {
    private List<RestaurantMenuItem> order;

    public RestaurantOrder() {
        order = new ArrayList<>();
    }

    // @Override optional
    public void add_item_to_order(RestaurantMenuItem item) {
        order.add(item);
    }

    public void remove_item_from_order(RestaurantMenuItem item) {
        order.remove(item);
    }

    public double calculateTotalPrice() {
        double total_price = 0.0;
        for (RestaurantMenuItem m : order) {
            total_price += m.getPrice();
        }
        return total_price;
    }

    public void displayOrder() {
        int i = 1;
        for (RestaurantMenuItem m : order)
            System.out.println(i++ + "." + m.getName());
    }

    public List<RestaurantMenuItem> getOrder() {
        return order;
    }
}

interface RestaurantSystem {
    List<RestaurantMenuItem> Create_Order(Scanner scanner);

    void add_to_restaurant(RestaurantMenuItem item);

    void delete_from_restaurant(RestaurantMenuItem item);
}

class RestaurantOrderSystem implements RestaurantSystem {
    private List<RestaurantMenuItem> available_food_items;

    RestaurantOrderSystem() {
        available_food_items = new ArrayList<>();
    }

    public void add_to_restaurant(RestaurantMenuItem m) {
        available_food_items.add(m);
    }

    public void delete_from_restaurant(RestaurantMenuItem m) {
        available_food_items.remove(m);
    }

    public RestaurantMenuItem isItemPresent(String name) {
        RestaurantMenuItem ispresent = null;
        for (RestaurantMenuItem m : available_food_items) {
            if (m.getName().toLowerCase().equals(name))
                ispresent = m;
        }
        return ispresent;
    }

    public void display_menu_in_restaurant() {
        int i = 1;
        System.out.println("Available food items in restaurant are :");
        for (RestaurantMenuItem m : available_food_items) {
            System.out.println(i++ + "." + m.getName() + " Rs " + m.getPrice());
        }
        System.out.println();
    }

    public List<RestaurantMenuItem> Create_Order(Scanner scanner) {
        // Order order = new RestaurantOrder();
        RestaurantOrder rso = new RestaurantOrder();
        display_menu_in_restaurant();
        int w = 1, n, found;
        String name;
        while (w != 0) {
            System.out.println("1.Add food item to your order");
            System.out.println("2.Remove food item from your order");
            System.out.println("3.Display order and give bill");
            n = scanner.nextInt();
            switch (n) {
                case 1:
                    System.out.println("Enter name of food item");
                    name = scanner.next().toLowerCase();
                    found = 0;
                    for (RestaurantMenuItem m : available_food_items) {
                        if (m.getName().toLowerCase().equals(name)) {
                            found = 1;
                            rso.add_item_to_order(m);
                        }
                    }
                    if (found != 1)
                        System.out.println("Food item not present in menu");
                    else
                        System.out.println("Food item added successdully to cart");
                    break;
                case 2:
                    System.out.println("Enter name of food item");
                    name = scanner.next().toLowerCase();
                    found = 0;
                    for (RestaurantMenuItem m : rso.getOrder()) {
                        if (m.getName().toLowerCase().equals(name)) {
                            found = 1;
                            rso.remove_item_from_order(m);
                        }
                    }
                    if (found != 1)
                        System.out.println("Food item not present in your order");
                    break;
                case 3:
                System.out.println("--------------------------------------------------------------------------");
                    System.out.println("Your order and bill");
                    rso.displayOrder();
                    System.out.println("Total bill is Rs " + rso.calculateTotalPrice());
                    System.out.println("--------------------------------------------------------------------------");
                    w = 0;
                    break;

                default:
                    System.out.println("Invalid input");
                    break;
            }
        }
        return rso.getOrder();
    }
}

public class restaurant {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        RestaurantMenuItem m1 = new RestaurantMenuItem("vadapav", "vada in pav", 15.5);
        RestaurantMenuItem m2 = new RestaurantMenuItem("samosa", "triangular in shape", 18.5);
        RestaurantMenuItem m3 = new RestaurantMenuItem("dhokla", "yellow cube", 20.5);
        RestaurantMenuItem m4 = new RestaurantMenuItem("dabheli", "pav with bhaji", 30);
        RestaurantMenuItem m5 = new RestaurantMenuItem("bhel", "tasty chat item", 40);

        RestaurantOrderSystem restaurant1 = new RestaurantOrderSystem();
        restaurant1.add_to_restaurant(m1);
        restaurant1.add_to_restaurant(m2);
        restaurant1.add_to_restaurant(m3);
        restaurant1.add_to_restaurant(m4);
        restaurant1.add_to_restaurant(m5);

        int q = 1, n;
        String name, des;
        double price;
        while (q == 1) {
            System.out.println("Welcome to Restaurant");
            System.out.println("\tOptions for owner");
            System.out.println("1.Add menu item to restaurant");
            System.out.println("2.Delete menu item from restaurant");
            System.out.println();
            System.out.println("\tOptions for customer");
            System.out.println("3.Create order");
            System.out.println("4.Display items in restaurant");
            System.out.println("5.Exit Restaurant");
            System.out.println("--------------------------------------------------------------------------");
                
            n = scanner.nextInt();
            switch (n) {
                case 1:
                    System.out.println("Enter name of menu item");
                    name = scanner.next();
                    System.out.println("Enter description of menu item");
                    des = scanner.next();
                    System.out.println("Enter price of menu item");
                    price = scanner.nextDouble();
                    RestaurantMenuItem m = new RestaurantMenuItem(name, des, price);
                    restaurant1.add_to_restaurant(m);
                    System.out.println(name + " menu item added successfully\n");
                    System.out.println("--------------------------------------------------------------------------");
                
                    break;
                case 2:
                    restaurant1.display_menu_in_restaurant();
                    System.out.println("Enter name of menu item to be deleted");
                    name = scanner.next().toLowerCase();
                    RestaurantMenuItem del_m = restaurant1.isItemPresent(name);
                    if (del_m != null) {
                        restaurant1.delete_from_restaurant(del_m);
                    }
                    System.out.println(name + " menu item deleted successfully\n");
                    System.out.println("--------------------------------------------------------------------------");
                

                    break;
                case 3:
                    restaurant1.Create_Order(scanner);
                    System.out.println("--------------------------------------------------------------------------");
                
                    break;
                case 4:
                    restaurant1.display_menu_in_restaurant();
                    System.out.println("--------------------------------------------------------------------------");
                
                    break;
                case 5:
                    q = 0;
                    System.out.println("Leaving the restaurant");
                    break;
                default:
                    System.out.println("Invalid input");
                    break;
            }

        }
    }
}
