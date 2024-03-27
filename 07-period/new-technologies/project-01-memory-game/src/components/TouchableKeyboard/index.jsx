import { View } from "react-native";
import { Button } from "../ui/Button";
import styles from "./styles";

export function TouchableKeyboard({
  currentIndex,
  setCurrentIndex,
  setNumbers,
  showResults = false,
}) {
  const getHandlePress = (number) => () => {
    setNumbers((prev) =>
      prev.map((item, index) =>
        index === currentIndex ? { ...item, typed: number } : item,
      ),
    );

    setCurrentIndex((prev) => prev + 1);
  };

  return (
    <View style={styles.container}>
      <View style={styles.row}>
        <Button onPress={getHandlePress(1)} style={styles.rowButton}>
          1
        </Button>
        <Button onPress={getHandlePress(2)} style={styles.rowButton}>
          2
        </Button>
        <Button onPress={getHandlePress(3)} style={styles.rowButton}>
          3
        </Button>
      </View>
      <View style={styles.row}>
        <Button onPress={getHandlePress(4)} style={styles.rowButton}>
          4
        </Button>
        <Button onPress={getHandlePress(5)} style={styles.rowButton}>
          5
        </Button>
        <Button onPress={getHandlePress(6)} style={styles.rowButton}>
          6
        </Button>
      </View>
      <View style={styles.row}>
        <Button onPress={getHandlePress(7)} style={styles.rowButton}>
          7
        </Button>
        <Button onPress={getHandlePress(8)} style={styles.rowButton}>
          8
        </Button>
        <Button onPress={getHandlePress(9)} style={styles.rowButton}>
          9
        </Button>
      </View>
      <View style={styles.row}>
        <Button onPress={getHandlePress(0)} style={styles.rowButton}>
          0
        </Button>
        <Button
          onPress={() => {
            if (!showResults) {
              setNumbers((prev) =>
                prev.map((item, index) =>
                  index === currentIndex - 1 ? { ...item, typed: "" } : item,
                ),
              );
              setCurrentIndex((prev) => prev - 1);
            }
          }}
          style={styles.rowButton}
        >
          🔙
        </Button>
      </View>
    </View>
  );
}
