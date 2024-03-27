import { TextInput, View } from "react-native";

import styles from "./styles";
import { BodyText } from "../ui/BodyText";
import { HeadingText } from "../ui/HeadingText";

export function CarouselInput({ hidden, numbers, showResults = true }) {
  const isFirstInputTyped = numbers[0] && numbers[0].typed !== "";

  return (
    <View>
      <View style={styles.container}>
        {numbers.map((item, index) => (
          <View
            style={styles.wrapper}
            key={`number-${item.number}-${String(index)}`}
            pointerEvents="none"
          >
            <TextInput
              style={styles.input}
              value={String(item.typed)}
              maxLength={1}
              pointerEvents="none"
            />
            {showResults && (
              <BodyText style={styles.indicator}>
                {item.number === item.typed ? "✅" : "❌"}
              </BodyText>
            )}
          </View>
        ))}
      </View>
      <BodyText
        style={{
          textAlign: "center",
          marginBottom: 40,
          opacity: !hidden && !isFirstInputTyped ? 1 : 0,
        }}
      >
        The sequence is: {"\n"}
        <HeadingText>
          {numbers.map((item) => item.number).join(" ")}
        </HeadingText>
      </BodyText>
    </View>
  );
}
