import { StatusBar, Text, View } from 'react-native';
import { styles } from './styles';

export function MyComponent({ color, children: text }) {
  return (
    <View style={styles.container}>
      <Text style={{ ...styles.text, color }}>{text}</Text>
      <StatusBar style="auto" />
    </View>
  );
}
