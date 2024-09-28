import react from '@vitejs/plugin-react'
import { resolve } from 'path'
import { defineConfig } from 'vite'

// https://vitejs.dev/config/
export default defineConfig({
	plugins: [react()],
	base: '/',
	build: {
		manifest: true,
		outDir: 'dist',
		rollupOptions: {
			input: {
				main: resolve(__dirname, 'index.html'),
			},
		},
	},
	server: {
		historyApiFallback: true,
	},
})
