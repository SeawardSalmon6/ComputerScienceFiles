import { Text, View } from "react-native";
import { styles } from "./styles";
import { useState } from "react";
import { useTextWidth } from "../../hooks/useTextWidth";

export function Header({
  showDivider = true,
  containerStyle,
  titleStyle,
  children,
  level = "h1",
}) {
  const { width, handleTextLayout } = useTextWidth();

  return (
    <View style={[styles.container, containerStyle]}>
      <Text
        onLayout={handleTextLayout}
        style={[styles.title, styles[level], titleStyle]}
      >
        {children}
      </Text>
      {showDivider && <View style={[styles.divider, { width: width + 8 }]} />}
    </View>
  );
}
